//
// Created by liu on 2016/12/10.
//

#include "FileInput.h"
#include <QFile>

namespace TCUIEdit { namespace Core
{
    const char *FileInput::TYPE_FILENAME[FileInput::TYPE_NUM] =
            {"TriggerData.txt", "TriggerStrings.txt", "WorldEditStrings.txt",
             "define.txt", "event.txt", "action.txt", "call.txt"
            };

    FileInput::CATEGORY FileInput::getCategory() const
    {
        if (this->category >= 0 && this->category < this->CATEGORY_NUM)return this->category;
        return CATEGORY_UNKNOWN;
    }

    FileInput::TYPE FileInput::getType() const
    {
        if (this->type >= 0 && this->type < this->TYPE_NUM)return this->type;
        return TYPE_UNKNOWN;
    }

    void FileInput::setType(TYPE type)
    {
        this->type = type;
        if (type == TYPE_UNKNOWN)
        {
            this->category = CATEGORY_UNKNOWN;
        }
        else if (type <= CLASSIC_WE_STRINGS)
        {
            this->category = CLASSIC;
        }
        else if (type <= YDWE_CALL)
        {
            this->category = YDWE;
        }
        else
        {
            this->category = CATEGORY_UNKNOWN;
        }
    }

    FileInput::FileInput()
    {
        this->stream = NULL;
        this->reset();
    }

    FileInput::FileInput(const QString &path, TYPE type)
    {
        this->stream = NULL;
        this->open(path, type);
    }

    FileInput::~FileInput()
    {
        if (this->stream)delete this->stream;
    }

    void FileInput::reset()
    {
        if (this->stream)delete this->stream;
        this->stream = NULL;
        this->lineNum = 0;
        this->data.clear();
        this->category = CATEGORY_UNKNOWN;
        this->type = TYPE_UNKNOWN;
    }

    void FileInput::open(const QString &path, TYPE type)
    {
        this->reset();
        this->setType(type);
        type = this->getType();
        if (type == TYPE_UNKNOWN)return;
        QFile qFile(path + TYPE_FILENAME[type]);
        if (qFile.open(QFile::ReadOnly))
        {
            this->data = qFile.readAll();
            this->stream = new QTextStream(this->data);
            this->stream->setCodec("UTF-8");
            /**
             * @TODO File Codec of input UI File
             * The default format of UI File is UTF-8
             * This version only supports UTF-8 encoding
             * The support of ANSI and UNICODE may be added later
             */
            this->lineNum = 0;
            qFile.close();
        }
        else
        {
            this->lineNum = -1;
        }
    }

    int FileInput::readLineInto(QString &line)
    {
        if (this->lineNum < 0)return 0;
        while (this->stream->readLineInto(&line))
        {
            this->lineNum++;
            auto pos = line.length();
            while (pos > 0)
            {
                if (!line[--pos].isSpace())break;
            }
            line = line.left(pos + 1);
            if (!line.isEmpty())
            {
                return this->lineNum;
            }
        }
        this->lineNum = -1;
        return 0;
    }

}}