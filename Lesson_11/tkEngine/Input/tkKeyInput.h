/*!
 * @brief	�L�[���́B
 */

#ifndef _TKKEYINPUT_H_ 
#define _TKKEYINPUT_H_ 

namespace tkEngine{
	class CKeyInput{
		
	public:
		enum EnKey {
			enKeyUp,
			enKeyDown,
			enKeyRight,
			enKeyLeft,
			enKeyA,
			enKeyB,
			enKeyNum,
		};
		/*!
		 * @brief	�R���X�g���N�^�B
		 */
		CKeyInput();
		/*!
		 * @brief	�f�X�g���N�^�B
		 */
		~CKeyInput();
		/*!
		 * @brief	�L�[���̍X�V�B
		 */
		void Update();
		/*!
		 * @brief	��L�[��������Ă���B
		 */
		bool IsUpPress() const
		{
			return m_keyPressFlag[enKeyUp];
		}
		/*!
		 * @brief	�E�L�[��������Ă���B
		 */
		bool IsRightPress() const
		{
			return m_keyPressFlag[enKeyRight];
		}
		/*!
		 * @brief	���L�[��������Ă���B
		 */
		bool IsLeftPress() const
		{
			return m_keyPressFlag[enKeyLeft];
		}
		/*!
		 * @brief	���L�[��������Ă���B
		 */
		bool IsDownPress() const
		{
			return m_keyPressFlag[enKeyDown];
		}
		/*!
		* @brief	�L�[�̃v���X����B
		*/
		bool IsPress(EnKey key) const
		{
			return m_keyPressFlag[key];
		}
		/*!
		* @brief	�L�[�̃g���K�[����B
		*/
		bool IsTrgger(EnKey key) const
		{
			return m_keyTrigerFlag[key];
		}
		/*!
		* @brief	�}�E�X�̍��{�^���������ꂽ�Ƃ��̏����B
		*/
		void OnMouseLButtonUp(int x, int y)
		{
			m_mousePositionX = x;
			m_mousePositionY = y;
			m_isMouseUp[1] = true;
		}
		/*!
		* @brief	�}�E�X�̍��{�^���������ꂽ�Ƃ�������B
		*/
		bool IsMouseLButtonUp() const
		{
			return m_isMouseUp[0];
		}
		/*!
		* @brief	�}�E�X��X���W���擾�B
		*/
		int GetMousePositionX() const
		{
			return m_mousePositionX;
		}
		/*!
		* @brief	�}�E�X��Y���W���擾�B
		*/
		int GetMousePositionY() const
		{
			return m_mousePositionY;
		}
	private:
		bool	m_keyPressFlag[enKeyNum];
		bool	m_keyTrigerFlag[enKeyNum];
		bool	m_isMouseUp[2];
		int		m_mousePositionX;
		int		m_mousePositionY;
	};
}
#endif //_TKKEYINPUT_H_ 