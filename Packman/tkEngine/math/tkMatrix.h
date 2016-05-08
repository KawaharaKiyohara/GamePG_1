/*!
 * @brief	�s��B
 */

#ifndef _TKMATRIX_H_
#define _TKMATRIX_H_

#include "tkEngine/math/tkVector.h"

namespace tkEngine{
	/*!
	 * @brief	�s��B
	 */
	class CMatrix{
	public:
		union {
			struct {
				float _11, _12, _13, _14;
				float _21, _22, _23, _24;
				float _31, _32, _33, _34;
				float _41, _42, _43, _44;
			};
			float m[4][4];
		};
		static const CMatrix Identity;	//!<�P�ʍs��B
	public:
		/*!
		*@brief	�x�N�g���ƍs��̏�Z
		*@param[in,out]		v	��Z�����x�N�g���B
		*/
		void Mul(CVector3& vOut)
		{
			CVector3 vTmp = vOut;
			vOut.x = vTmp.x * m[0][0] + vTmp.y * m[0][1] + vTmp.z * m[0][2];
			vOut.y = vTmp.x * m[1][0] + vTmp.y * m[1][1] + vTmp.z * m[1][2];
			vOut.z = vTmp.x * m[2][0] + vTmp.y * m[2][1] + vTmp.z * m[2][2];
		}
		/*!
		 *@brief	���s�ړ��s����쐬�B
		 */
		void MakeTranslation( const CVector3& trans ) 
		{
			*this = Identity;
			m[3][0] = trans.x; 
			m[3][1] = trans.y;
			m[3][2] = trans.z;
		}
		/*!
		*@brief	Y������̉�]�s����쐬�B
		*@param[in]	angle	��]�p�x(�P�ʃ��W�A��)
		*/
		void MakeRotationY(float angle)
		{
			D3DXMatrixRotationY(
				r_cast<D3DXMATRIX*>(this),
				angle
			);
		}
		/*!
		 *@brief	�N�H�[�^�j�I�������]�s����쐬�B
		 *@param[in]	q		�N�H�[�^�j�I��
		 */
		void MakeRotationFromQuaternion( const CQuaternion& q )
		{
			D3DXMatrixRotationQuaternion(
				r_cast<D3DXMATRIX*>(this),
				r_cast<const D3DXQUATERNION*>(&q)
			);
		}
		/*!
		* @brief	�v���W�F�N�V�����s����쐬�B
		*@param[in]	viewAngle	��p�B(���W�A��)�B
		*@param[in]	aspect		�A�X�y�N�g��B
		*@param[in]	fNear		�ߕ��ʁB
		*@param[in]	fFar		�����ʁB
		*/
		void MakeProjectionMatrix(
			float viewAngle,
			float aspect,
			float fNear,
			float fFar
			)
		{
			D3DXMatrixPerspectiveFovLH(
				r_cast<D3DXMATRIX*>(this),
				viewAngle,
				aspect,
				fNear,
				fFar
			);
		}
		/*!
		 * @brief	�����_�A������A�J�����ʒu����J�����s����쐬�B
		 *@param[in]	position	�J�����ʒu�B
		 *@param[in]	target		�����_�B
		 *@param[in]	up			�J�����̏�����B
		 */
		void MakeLookAt( const CVector3& position, const CVector3& target, const CVector3& up )
		{
			D3DXMatrixLookAtLH(
				r_cast<D3DXMATRIX*>(this),
				r_cast<const D3DXVECTOR3*>(&position),
				r_cast<const D3DXVECTOR3*>(&target),
				r_cast<const D3DXVECTOR3*>(&up)
			);
		}
		/*!
		 *@brief	�s��ƍs��̏�Z
		 *@details
		 * *this = m0 * m1
		 */
		void Mul( const CMatrix& m0, const CMatrix& m1 )
		{
			D3DXMatrixMultiply(
				r_cast<D3DXMATRIX*>(this),
				r_cast<const D3DXMATRIX*>(&m0),
				r_cast<const D3DXMATRIX*>(&m1)
			);
		}
		/*!
		 *@brief	�t�s����v�Z�B
		 *@param[in]	m	���ɂȂ�s��B
		 */
		void Inverse( const CMatrix& m )
		{
			D3DXMatrixInverse(
				r_cast<D3DXMATRIX*>(this),
				NULL,
				r_cast<const D3DXMATRIX*>(&m)
			);
		}
		void Transpose()
		{
			D3DXMatrixTranspose(r_cast<D3DXMATRIX*>(this), r_cast<D3DXMATRIX*>(this));
		}
		
	};
};
#endif // _TKMATRIX_H_