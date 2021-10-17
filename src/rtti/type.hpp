#pragma once

#include <string>

#include "rtti_fwd.hpp"

namespace rtti {

    //*********************************************************************************************
    //*********************************************************************************************
    //*********************************************************************************************
    class Type {
    public:
        Type(std::string name, size_t size) : m_name(std::move(name)), m_size(size) {}

        const std::string& name() const { return m_name; }
        const size_t size() const { return m_size; }

        virtual Object new_object() const = 0;
        virtual Object call_constructor(Buffer&& buff) const = 0;
        virtual void delete_object(Object&& obj) const = 0;
        virtual Buffer call_destructor(Object&& obj) const = 0;
        virtual void copy(ObjectRef& dst, const ObjectRef& src) const = 0;
        virtual Object copy_construct(const ObjectRef& src) const = 0;
        virtual void move(ObjectRef& dst, ObjectRef& src) const = 0;
        virtual Object move_construct(ObjectRef& src) const = 0;

        virtual const Class* as_class() const = 0;
        virtual const Enum* as_enum() const = 0;
        virtual const Fundamental* as_fundamental() = 0;

    protected:
        void* writable_data(Buffer&) const;
        void* writable_data(ObjectRef&) const;
        void* move_data(Buffer&&) const;
        void* move_data(Object&&) const;

    private:
        const std::string m_name;
        const size_t m_size = 0;

    } // class Type

} // namespace rtti