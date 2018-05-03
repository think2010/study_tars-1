// **********************************************************************
// This file was generated by a TARS parser!
// TARS version 1.1.0.
// **********************************************************************

#ifndef __CSERVANT_H_
#define __CSERVANT_H_

#include <map>
#include <string>
#include <vector>
#include "tup/Tars.h"
using namespace std;
#include "servant/ServantProxy.h"
#include "servant/Servant.h"
#include "promise/promise.h"


namespace Test
{

    /* callback of async proxy for client */
    class CServantPrxCallback: public tars::ServantProxyCallback
    {
    public:
        virtual ~CServantPrxCallback(){}
        virtual void callback_queryResult(tars::Int32 ret,  const std::string& sOut)
        { throw std::runtime_error("callback_queryResult() override incorrect."); }
        virtual void callback_queryResult_exception(tars::Int32 ret)
        { throw std::runtime_error("callback_queryResult_exception() override incorrect."); }

    public:
        virtual const map<std::string, std::string> & getResponseContext() const
        {
            CallbackThreadData * pCbtd = CallbackThreadData::getData();
            assert(pCbtd != NULL);

            if(!pCbtd->getContextValid())
            {
                throw TC_Exception("cann't get response context");
            }
            return pCbtd->getResponseContext();
        }

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __CServant_all[]=
            {
                "queryResult"
            };
            pair<string*, string*> r = equal_range(__CServant_all, __CServant_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __CServant_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_queryResult_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    tars::Int32 _ret;
                    _is.read(_ret, 0, true);

                    std::string sOut;
                    _is.read(sOut, 2, true);
                    CallbackThreadData * pCbtd = CallbackThreadData::getData();
                    assert(pCbtd != NULL);

                    pCbtd->setResponseContext(msg->response.context);

                    callback_queryResult(_ret, sOut);

                    pCbtd->delResponseContext();

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<CServantPrxCallback> CServantPrxCallbackPtr;

    /* callback of promise async proxy for client */
    class CServantPrxCallbackPromise: public tars::ServantProxyCallback
    {
    public:
        virtual ~CServantPrxCallbackPromise(){}
    public:
        struct PromisequeryResult: virtual public TC_HandleBase
        {
        public:
            tars::Int32 _ret;
            std::string sOut;
            map<std::string, std::string> _mRspContext;
        };
        
        typedef tars::TC_AutoPtr< CServantPrxCallbackPromise::PromisequeryResult > PromisequeryResultPtr;

        CServantPrxCallbackPromise(const promise::Promise< CServantPrxCallbackPromise::PromisequeryResultPtr > &promise)
        : _promise_queryResult(promise)
        {}
        
        virtual void callback_queryResult(const CServantPrxCallbackPromise::PromisequeryResultPtr &ptr)
        {
            _promise_queryResult.setValue(ptr);
        }
        virtual void callback_queryResult_exception(tars::Int32 ret)
        {
            std::string str("");
            str += "Function:queryResult_exception|Ret:";
            str += TC_Common::tostr(ret);
            _promise_queryResult.setException(promise::copyException(str, ret));
        }

    protected:
        promise::Promise< CServantPrxCallbackPromise::PromisequeryResultPtr > _promise_queryResult;

    public:
        virtual int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __CServant_all[]=
            {
                "queryResult"
            };

            pair<string*, string*> r = equal_range(__CServant_all, __CServant_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __CServant_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_queryResult_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);

                    CServantPrxCallbackPromise::PromisequeryResultPtr ptr = new CServantPrxCallbackPromise::PromisequeryResult();

                    try
                    {
                        _is.read(ptr->_ret, 0, true);

                        _is.read(ptr->sOut, 2, true);
                    }
                    catch(std::exception &ex)
                    {
                        callback_queryResult_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_queryResult_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    ptr->_mRspContext = msg->response.context;

                    callback_queryResult(ptr);

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    };
    typedef tars::TC_AutoPtr<CServantPrxCallbackPromise> CServantPrxCallbackPromisePtr;

    /* callback of coroutine async proxy for client */
    class CServantCoroPrxCallback: public CServantPrxCallback
    {
    public:
        virtual ~CServantCoroPrxCallback(){}
    public:
        virtual const map<std::string, std::string> & getResponseContext() const { return _mRspContext; }

        virtual void setResponseContext(const map<std::string, std::string> &mContext) { _mRspContext = mContext; }

    public:
        int onDispatch(tars::ReqMessagePtr msg)
        {
            static ::std::string __CServant_all[]=
            {
                "queryResult"
            };

            pair<string*, string*> r = equal_range(__CServant_all, __CServant_all+1, string(msg->request.sFuncName));
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __CServant_all)
            {
                case 0:
                {
                    if (msg->response.iRet != tars::TARSSERVERSUCCESS)
                    {
                        callback_queryResult_exception(msg->response.iRet);

                        return msg->response.iRet;
                    }
                    tars::TarsInputStream<tars::BufferReader> _is;

                    _is.setBuffer(msg->response.sBuffer);
                    try
                    {
                        tars::Int32 _ret;
                        _is.read(_ret, 0, true);

                        std::string sOut;
                        _is.read(sOut, 2, true);
                        setResponseContext(msg->response.context);

                        callback_queryResult(_ret, sOut);

                    }
                    catch(std::exception &ex)
                    {
                        callback_queryResult_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }
                    catch(...)
                    {
                        callback_queryResult_exception(tars::TARSCLIENTDECODEERR);

                        return tars::TARSCLIENTDECODEERR;
                    }

                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }

    protected:
        map<std::string, std::string> _mRspContext;
    };
    typedef tars::TC_AutoPtr<CServantCoroPrxCallback> CServantCoroPrxCallbackPtr;

    /* proxy for client */
    class CServantProxy : public tars::ServantProxy
    {
    public:
        typedef map<string, string> TARS_CONTEXT;
        tars::Int32 queryResult(const std::string & sIn,std::string &sOut,const map<string, string> &context = TARS_CONTEXT(),map<string, string> * pResponseContext = NULL)
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sIn, 1);
            _os.write(sOut, 2);
            tars::ResponsePacket rep;
            std::map<string, string> _mStatus;
            tars_invoke(tars::TARSNORMAL,"queryResult", _os.getByteBuffer(), context, _mStatus, rep);
            if(pResponseContext)
            {
                *pResponseContext = rep.context;
            }

            tars::TarsInputStream<tars::BufferReader> _is;
            _is.setBuffer(rep.sBuffer);
            tars::Int32 _ret;
            _is.read(_ret, 0, true);
            _is.read(sOut, 2, true);
            return _ret;
        }

        void async_queryResult(CServantPrxCallbackPtr callback,const std::string &sIn,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sIn, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"queryResult", _os.getByteBuffer(), context, _mStatus, callback);
        }
        
        promise::Future< CServantPrxCallbackPromise::PromisequeryResultPtr > promise_async_queryResult(const std::string &sIn,const map<string, string>& context)
        {
            promise::Promise< CServantPrxCallbackPromise::PromisequeryResultPtr > promise;
            CServantPrxCallbackPromisePtr callback = new CServantPrxCallbackPromise(promise);

            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sIn, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"queryResult", _os.getByteBuffer(), context, _mStatus, callback);

            return promise.getFuture();
        }

        void coro_queryResult(CServantCoroPrxCallbackPtr callback,const std::string &sIn,const map<string, string>& context = TARS_CONTEXT())
        {
            tars::TarsOutputStream<tars::BufferWriter> _os;
            _os.write(sIn, 1);
            std::map<string, string> _mStatus;
            tars_invoke_async(tars::TARSNORMAL,"queryResult", _os.getByteBuffer(), context, _mStatus, callback, true);
        }

        CServantProxy* tars_hash(int64_t key)
        {
            return (CServantProxy*)ServantProxy::tars_hash(key);
        }

        CServantProxy* tars_consistent_hash(int64_t key)
        {
            return (CServantProxy*)ServantProxy::tars_consistent_hash(key);
        }

        CServantProxy* tars_set_timeout(int msecond)
        {
            return (CServantProxy*)ServantProxy::tars_set_timeout(msecond);
        }

    };
    typedef tars::TC_AutoPtr<CServantProxy> CServantPrx;

    /* servant for server */
    class CServant : public tars::Servant
    {
    public:
        virtual ~CServant(){}
        virtual tars::Int32 queryResult(const std::string & sIn,std::string &sOut,tars::TarsCurrentPtr current) = 0;
        static void async_response_queryResult(tars::TarsCurrentPtr current, tars::Int32 _ret, const std::string &sOut)
        {
            if (current->getRequestVersion() == TUPVERSION )
            {
                UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                tarsAttr.setVersion(current->getRequestVersion());
                tarsAttr.put("", _ret);
                tarsAttr.put("sOut", sOut);

                vector<char> sTupResponseBuffer;
                tarsAttr.encode(sTupResponseBuffer);
                current->sendResponse(tars::TARSSERVERSUCCESS, sTupResponseBuffer);
            }
            else
            {
                tars::TarsOutputStream<tars::BufferWriter> _os;
                _os.write(_ret, 0);

                _os.write(sOut, 2);

                current->sendResponse(tars::TARSSERVERSUCCESS, _os.getByteBuffer());
            }
        }

    public:
        int onDispatch(tars::TarsCurrentPtr _current, vector<char> &_sResponseBuffer)
        {
            static ::std::string __Test__CServant_all[]=
            {
                "queryResult"
            };

            pair<string*, string*> r = equal_range(__Test__CServant_all, __Test__CServant_all+1, _current->getFuncName());
            if(r.first == r.second) return tars::TARSSERVERNOFUNCERR;
            switch(r.first - __Test__CServant_all)
            {
                case 0:
                {
                    tars::TarsInputStream<tars::BufferReader> _is;
                    _is.setBuffer(_current->getRequestBuffer());
                    std::string sIn;
                    std::string sOut;
                    if (_current->getRequestVersion() == TUPVERSION)
                    {
                        UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                        tarsAttr.setVersion(_current->getRequestVersion());
                        tarsAttr.decode(_current->getRequestBuffer());
                        tarsAttr.get("sIn", sIn);
                        tarsAttr.getByDefault("sOut", sOut, sOut);
                    }
                    else
                    {
                        _is.read(sIn, 1, true);
                        _is.read(sOut, 2, false);
                    }
                    tars::Int32 _ret = queryResult(sIn,sOut, _current);
                    if(_current->isResponse())
                    {
                        if (_current->getRequestVersion() == TUPVERSION )
                        {
                            UniAttribute<tars::BufferWriter, tars::BufferReader>  tarsAttr;
                            tarsAttr.setVersion(_current->getRequestVersion());
                            tarsAttr.put("", _ret);
                            tarsAttr.put("sOut", sOut);
                            tarsAttr.encode(_sResponseBuffer);
                        }
                        else
                        {
                            tars::TarsOutputStream<tars::BufferWriter> _os;
                            _os.write(_ret, 0);
                            _os.write(sOut, 2);
                            _os.swap(_sResponseBuffer);
                        }
                    }
                    return tars::TARSSERVERSUCCESS;

                }
            }
            return tars::TARSSERVERNOFUNCERR;
        }
    };


}



#endif