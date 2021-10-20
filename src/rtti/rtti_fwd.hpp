#pragma once

namespace rtti {

    class Type;
    class Class;
    class Enum;
    class Fundamental;

    class ObjectRef;
    class Object;
    class Buffer;

    class Member;
    class Field;
    class Property;
    class Method;

    class Attributes;

    template <typename TYPE>
    inline const Type* static_type() { return TYPE::static_class(); }

    template <typename CLASS>
    inline const Class* static_class() { return CLASS::static_class(); }
    
    template <typename CLASS>
    inline const Class* dynamic_class(CLASS& obj) { return obj.dynamic_class(); }

} // namespace rtti