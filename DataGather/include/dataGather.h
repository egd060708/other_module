#pragma once
#include <stdFile.h>

class DataGather{
    private:
        std::ofstream* csvFile;// 文件指针
    public:
        DataGather(const std::string& _fileName){
            // 分配一个文件流对象
            this->csvFile = new std::ofstream(_fileName);
        }
        ~DataGather(){
            delete this->csvFile;
        }
};