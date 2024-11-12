#include <Windows.h>

#include "Audio/AudioManager.h"
#include "Utils/Assertion.h"
#include "Utils/MemoryAlloc.h"

ma_engine* gAudioEnginePtr = nullptr;

AudioManager AudioManager::singleton_;

AudioManager& AudioManager::GetRef()
{
	return singleton_;
}

AudioManager* AudioManager::GetPtr()
{
	return &singleton_;
}

void AudioManager::Destroy(const Sound* sound)
{
	int32_t soundID = -1;
	for (uint32_t index = 0; index < soundSize_; ++index)
	{
		Sound* soundPtr = sounds_[index].get();
		if (sound == soundPtr)
		{
			soundID = static_cast<int32_t>(index);
			break;
		}
	}

	if (soundID == -1)
	{
		return; // �ش� ����� �̹� �Ҵ� ���� �Ǿ��ų�, ����� �Ŵ����� ���� �Ҵ� ������ ���� �Դϴ�.
	}

	if (sounds_[soundID])
	{
		if (sounds_[soundID]->IsInitialized())
		{
			sounds_[soundID]->Release();
		}

		sounds_[soundID].reset();
		usages_[soundID] = false;
	}
}

void AudioManager::Startup()
{
	audioEngine_ = std::make_unique<ma_engine>();
	gAudioEnginePtr = audioEngine_.get();

	ma_allocation_callbacks allocationCallbacks;
	allocationCallbacks.pUserData = nullptr;
	allocationCallbacks.onMalloc = MemoryAlloc;
	allocationCallbacks.onRealloc = MemoryRealloc;
	allocationCallbacks.onFree = MemoryFree;

	ma_engine_config config;
	ZeroMemory(&config, sizeof(ma_engine_config));

	config.allocationCallbacks = allocationCallbacks;

	ma_result result = ma_engine_init(&config, gAudioEnginePtr);
	ASSERTION(result == MA_SUCCESS, "Failed to initialize miniaudio engine.");
}

void AudioManager::Shutdown()
{
	for (uint32_t index = 0; index < soundSize_; ++index)
	{
		if (sounds_[index])
		{
			if (sounds_[index]->IsInitialized())
			{
				sounds_[index]->Release();
			}

			sounds_[index].reset();
			usages_[index] = false;
		}
	}

	ma_engine_uninit(gAudioEnginePtr);
	audioEngine_.reset();
	gAudioEnginePtr = nullptr;
}