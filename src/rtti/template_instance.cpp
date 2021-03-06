#include "template_instance.hpp"

using namespace rtti;

//*************************************************************************************************
//*************************************************************************************************
//*************************************************************************************************
TemplateInstance::TemplateInstance(std::string name, size_t size, Attributes attributes
    , std::vector<TemplateParam> params) 
    : Class(std::move(name), size, std::move(attributes)), m_params(std::move(params))
{
    for (TemplateParam& param : m_params) {
        param.m_declaring_template_instance = this;
        m_params_ptrs.push_back(&param);
    }
}