#pragma once
#include <DxLib.h>
/// <summary>
		/// �x�N�g���̐ݒ�B
		/// </summary>
		/// <param name="_x"></param>
		/// <param name="_y"></param>
		/// <param name="_z"></param>
		
		
		VECTOR Set(const VECTOR& _v)
		{
			return VGet(_v.x, _v.y, _v.z);
		}