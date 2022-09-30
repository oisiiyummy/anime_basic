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
}

void Player::update()
{
	// パッド(もしくはキーボード)からの入力を取得する
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (padState & PAD_INPUT_UP)
	{
		m_animeFrame++;
		if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}
		m_animeNo = m_animeFrame / kAnimeChangeFrame + 9;
		m_pos.y -= kSpeed;
	}
	if (padState & PAD_INPUT_DOWN)
	{
		m_animeFrame++;
		if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}

		m_animeNo = m_animeFrame / kAnimeChangeFrame;
		m_pos.y += kSpeed;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_animeFrame++;
		if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}

		m_animeNo = m_animeFrame / kAnimeChangeFrame + 3;
		m_pos.x -= kSpeed;
	}
	if (padState & PAD_INPUT_RIGHT)
	{
		m_animeFrame++;
		if (m_animeFrame >= kPlayerGraphicDivX * kAnimeChangeFrame)
		{
			m_animeFrame = 0;
		}

		m_animeNo = m_animeFrame / kAnimeChangeFrame + 6;
		m_pos.x += kSpeed;
	}
}

void Player::draw()
{
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "%d",);
	DrawGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y), m_handle[m_animeNo], true);
}