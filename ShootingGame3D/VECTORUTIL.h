#pragma once
#include <DxLib.h>
/// <summary>
		/// ベクトルの設定。
		/// </summary>
		/// <param name="_x"></param>
		/// <param name="_y"></param>
		/// <param name="_z"></param>
		VECTOR VSet(float _x, float _y, float _z)
		{
			VECTOR vec;
			vec.x = _x;
			vec.y = _y;
			vec.z = _z;
			return vec;
		}
		template<class TVector>
		void Set(TVector& _v)
		{
			Set(_v.x, _v.y, _v.z);
		}