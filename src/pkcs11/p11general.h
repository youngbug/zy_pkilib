/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(����),Beijing,P.R.China
* All rights reserved.
* @filename:  p11general.h
* @author:  ���� Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.3
* @brief:  PKCS#11 �ӿ��е�һ�㺯��
*/

#ifndef __P11GENERIC_H_INC__
#define __P11GENERIC_H_INC__

#include "cryptoki.h"

#ifdef DEBUG
#define FUNC_CALLED() do { \
		debug("Function %s called.\n", __FUNCTION__); \
} while (0)

#define FUNC_RETURNS(rc) do { \
		debug("Function %s completes with rc=%d.\n", __FUNCTION__, (rc)); \
		return rc; \
} while (0)

#define FUNC_FAILS(rc, msg) do { \
		debug("Function %s fails with rc=%d \"%s\"\n", __FUNCTION__, (rc), (msg)); \
		return rc; \
} while (0)

#else
#define FUNC_CALLED()
#define FUNC_RETURNS(rc) return (rc)
#define FUNC_FAILS(rc, msg) return (rc)
#endif

#define CALLER_UNKNOWN			0
#define CALLER_FIREFOX			1

/**
* ���п��õ�slot��Ϣ
*
*/
struct p11SlotPool_t {
	CK_ULONG numberOfSlots;         /**< slot����slot����         */
	CK_SLOT_ID nextSlotID;          /**< �������һ��slot ID     */
	struct p11Slot_t *list;         /**< ���е�һ��slot��ָ��       */
};



/**
*  �Ự��Ϣ
*
*/
struct p11SessionPool_t {
	CK_ULONG numberOfSessions;              /**< session������           */
	CK_SESSION_HANDLE nextSessionHandle;    /**< ��һ�������session��ֵ */
	struct p11Session_t *list;              /**< ���еĵ�һ��session��ָ��      */
};

struct p11Context_t {
	CK_VERSION version;                     /**< cryptoki version       */
	CK_INFO info;                           /**< cryptoki ��Ϣ       */
	CK_HW_FEATURE_TYPE hw_feature;          /**< Ӳ����������          */

	int caller;                             /**< ����Ӧ��                     */
	//FILE *debugFileHandle;
	struct p11SessionPool_t sessionPool;    /**< �Ự��	                            */
	struct p11SlotPool_t slotPool;          /**< ����slot��                  */
	void *mutex;                            /**< �������    */
};

CK_RV p11CreateMutex(CK_VOID_PTR_PTR ppMutex);
CK_RV p11DestroyMutex(CK_VOID_PTR pMutex);
CK_RV p11LockMutex(CK_VOID_PTR pMutex);
CK_RV p11UnlockMutex(CK_VOID_PTR pMutex);

#endif