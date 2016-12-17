/*
* ZY PKCS#11 Module
* Copyright(C),2016, Zhao Yang(����),Beijing,P.R.China
* All rights reserved.
* @filename:  zyutility.h
* @author:  ���� Zhao Yang (cnrgc@163.com/sxzhaoyang@gmail.com)
* @version:  0.1
* @date:  2016.12.17
* @brief:  PKCS#11 �ӿ��е�һ�㺯��
*/

#ifndef __ZYUTILITY_H__
#define __ZYUTILITY_H__

#include <stdio.h>
#include <string.h>

#include "cryptoki.h"

void strbpcpy(CK_CHAR *dst, const char *src, int dstsize);


#endif // !__ZYUTILITY_H__
