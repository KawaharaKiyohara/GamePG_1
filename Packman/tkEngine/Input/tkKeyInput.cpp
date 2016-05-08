/*!
 * @brief	�L�[����
 */
 
#include "tkEngine/tkEnginePreCompile.h"
#include "tkEngine/Input/tkKeyInput.h"
#define VK_A			  0x41
#define VK_W			  0x57
namespace tkEngine{
	/*!
	 * @brief	�R���X�g���N�^�B
	 */
	CKeyInput::CKeyInput()
	{
		memset(m_keyPressFlag, 0, sizeof(m_keyPressFlag));
	}
	/*!
	 * @brief	�f�X�g���N�^�B
	 */
	CKeyInput::~CKeyInput()
	{
	}
	/*!
	 * @brief	�L�[���̍X�V�B
	 */
	void CKeyInput::Update()
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			m_keyPressFlag[enKeyUp] = true;
		}
		else {
			m_keyPressFlag[enKeyUp] = false;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			m_keyPressFlag[enKeyDown] = true;
		}
		else {
			m_keyPressFlag[enKeyDown] = false;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			m_keyPressFlag[enKeyRight] = true;
		}
		else {
			m_keyPressFlag[enKeyRight] = false;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			m_keyPressFlag[enKeyLeft] = true;
		}
		else {
			m_keyPressFlag[enKeyLeft] = false;
		}
		if (GetAsyncKeyState(VK_A) & 0x8000)
		{
			m_keyPressFlag[enkeyA] = true;
		}
		else
		{
			m_keyPressFlag[enkeyA] = false;
		}
		if (GetAsyncKeyState(VK_W) & 0x8000)
		{
			m_keyPressFlag[enkeyW] = true;
		}
		else
		{
			m_keyPressFlag[enkeyW] = false;
		}
	}
}
