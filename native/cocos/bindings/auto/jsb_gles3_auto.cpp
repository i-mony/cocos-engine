#include "cocos/bindings/auto/jsb_gles3_auto.h"
#include "cocos/bindings/manual/jsb_conversions.h"
#include "cocos/bindings/manual/jsb_global.h"
#include "renderer/gfx-gles3/GFXGLES3.h"

#ifndef JSB_ALLOC
#define JSB_ALLOC(kls, ...) new (std::nothrow) kls(__VA_ARGS__)
#endif

#ifndef JSB_FREE
#define JSB_FREE(ptr) delete ptr
#endif
se::Object* __jsb_cc_gfx_GLES3Device_proto = nullptr;
se::Class* __jsb_cc_gfx_GLES3Device_class = nullptr;

SE_DECLARE_FINALIZE_FUNC(js_cc_gfx_GLES3Device_finalize)

static bool js_gles3_GLES3Device_constructor(se::State& s) // constructor.c
{
    cc::gfx::GLES3Device* cobj = JSB_ALLOC(cc::gfx::GLES3Device);
    s.thisObject()->setPrivateData(cobj);
    se::NonRefNativePtrCreatedByCtorMap::emplace(cobj);
    return true;
}
SE_BIND_CTOR(js_gles3_GLES3Device_constructor, __jsb_cc_gfx_GLES3Device_class, js_cc_gfx_GLES3Device_finalize)



extern se::Object* __jsb_cc_gfx_Device_proto;

static bool js_cc_gfx_GLES3Device_finalize(se::State& s)
{
    auto iter = se::NonRefNativePtrCreatedByCtorMap::find(SE_THIS_OBJECT<cc::gfx::GLES3Device>(s));
    if (iter != se::NonRefNativePtrCreatedByCtorMap::end())
    {
        se::NonRefNativePtrCreatedByCtorMap::erase(iter);
        cc::gfx::GLES3Device* cobj = SE_THIS_OBJECT<cc::gfx::GLES3Device>(s);
        JSB_FREE(cobj);
    }
    return true;
}
SE_BIND_FINALIZE_FUNC(js_cc_gfx_GLES3Device_finalize)

bool js_register_gles3_GLES3Device(se::Object* obj)
{
    auto cls = se::Class::create("GLES3Device", obj, __jsb_cc_gfx_Device_proto, _SE(js_gles3_GLES3Device_constructor));

    cls->defineFinalizeFunction(_SE(js_cc_gfx_GLES3Device_finalize));
    cls->install();
    JSBClassType::registerClass<cc::gfx::GLES3Device>(cls);

    __jsb_cc_gfx_GLES3Device_proto = cls->getProto();
    __jsb_cc_gfx_GLES3Device_class = cls;

    se::ScriptEngine::getInstance()->clearException();
    return true;
}

bool register_all_gles3(se::Object* obj)
{
    // Get the ns
    se::Value nsVal;
    if (!obj->getProperty("gfx", &nsVal))
    {
        se::HandleObject jsobj(se::Object::createPlainObject());
        nsVal.setObject(jsobj);
        obj->setProperty("gfx", nsVal);
    }
    se::Object* ns = nsVal.toObject();

    js_register_gles3_GLES3Device(ns);
    return true;
}

