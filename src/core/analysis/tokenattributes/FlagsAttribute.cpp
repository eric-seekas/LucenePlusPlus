/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2011 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#include "LuceneInc.h"
#include "FlagsAttribute.h"
#include "StringUtils.h"

namespace Lucene
{
    FlagsAttribute::FlagsAttribute()
    {
        flags = 0;
    }
    
    FlagsAttribute::~FlagsAttribute()
    {
    }
    
    String FlagsAttribute::toString()
    {
        return L"flags=" + StringUtils::toString(flags);
    }
    
    int32_t FlagsAttribute::getFlags()
    {
        return flags;
    }
    
    void FlagsAttribute::setFlags(int32_t flags)
    {
        this->flags = flags;
    }
    
    void FlagsAttribute::clear()
    {
        flags = 0;
    }
    
    bool FlagsAttribute::equals(LuceneObjectPtr other)
    {
        if (Attribute::equals(other))
            return true;
        
        FlagsAttributePtr otherFlagsAttribute(LuceneDynamicCast<FlagsAttribute>(other));
        if (otherFlagsAttribute)
            return (otherFlagsAttribute->flags == flags);
        
        return false;
    }
    
    int32_t FlagsAttribute::hashCode()
    {
        return flags;
    }
    
    void FlagsAttribute::copyTo(AttributePtr target)
    {
        LuceneDynamicCast<FlagsAttribute>(target)->setFlags(flags);
    }
    
    LuceneObjectPtr FlagsAttribute::clone(LuceneObjectPtr other)
    {
        LuceneObjectPtr clone = other ? other : newLucene<FlagsAttribute>();
        FlagsAttributePtr cloneAttribute(LuceneDynamicCast<FlagsAttribute>(Attribute::clone(clone)));
        cloneAttribute->flags = flags;
        return cloneAttribute;
    }
}
