#ifndef DATAMGR_H
#define DATAMGR_H

#include "JsonMgr.h"
#include "TomlMgr.h"
#include "XmlMgr.h"
#include "YamlMgr.h"

class DataMgr
{
private:
    JsonMgr m_JsonMgr;
    YamlMgr m_YamlMgr;
    TomlMgr m_TomlMgr;
    XmlMgr m_XmlMgr;

public:
    DataMgr();
};

#endif // DATAMGR_H
