#include "DxLib.h"
#include <cassert>
#include "game.h"
#include "player.h"

namespace
{
	// キャラクターアニメーションの速度
	int kAnimeChangeFrame = 8;
	// キャラクターの移動スピード
	int kSpeed = 4;
}

Player::Player()
{
	for (auto& handle : m_handle)
	{
		handle = -1;
	}
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
}

Player::~Player()
{
	
}

void Player::init()
{
	m_pos.x = Game::kScreenWidth / 2 - kPlayerGraphicSizeX / 2;
	m_pos.y = Game::kScreenHeight / 2 - kPlayerGraphicSizeY / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_animeNo = 0;
	m_animeFrame = 0;
	m_dirNo = 0;
}

void Player::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_dirNo = 3;
		/*m_animeFrame++;
		if (m_animeFrame >= (kPlayerGraphicDivX + 1) * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}
		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3)
		{
			m_animeNo = 1;
		}
		m_animeNo += Player::kOrientationChangeUp;
		m_pos.y -= kSpeed;*/
	}

	if (padState & PAD_INPUT_DOWN)
	{
		m_dirNo = 0;
		//m_animeFrame++;
		//if (m_animeFrame >= (kPlayerGraphicDivX + 1) * kAnimeChangeFrame)
		//{
		//	m_animeFrame = 0;
		//}

		//m_animeNo = m_animeFrame / kAnimeChangeFrame;
		//if (m_animeNo == 3)
		//{
		//	m_animeNo = 1;
		//}
		////m_animeNo += Player::kOrientationChangeUp;
		//m_pos.y += kSpeed;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_dirNo = 1;
		/*m_animeFrame++;
		if (m_animeFrame >= (kPlayerGraphicDivX + 1) * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}

		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3)
		{
			m_animeNo = 1;
		}
		m_animeNo += Player::kOrientationChangeLeft;
		m_pos.x -= kSpeed;*/
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		m_dirNo = 2;
		/*m_animeFrame++;
		if (m_animeFrame >= (kPlayerGraphicDivX + 1)  * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}

		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		if (m_animeNo == 3)
		{
			m_animeNo = 1;
		}
		m_animeNo += Player::kOrientationChangeRight;
		m_pos.x += kSpeed;*/
	}
	m_animeFrame++;
	if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
	{
		m_animeFrame = 0;
	}

	int tempAnimeNo = m_animeFrame / kAnimeChangeFrame;
	m_animeNo = m_dirNo * kPlayerGraphicDivX + tempAnimeNo;
}

void Player::draw()
{
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d",);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
	//DrawExtendGraph(32, 32, Game::kScreenWidth - 32, Game::kScreenHeight - 32, m_handle[m_animeNo], true);
}