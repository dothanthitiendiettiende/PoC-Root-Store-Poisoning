#pragma once
#include <Neat\Types.h>
#include <Neat\Handle.h>

#include <Windows.h>

class CryptKey
{
	CryptKey();

public:
	CryptKey(CryptKey&& other) = default;
	CryptKey& operator=(CryptKey&& other) = default;

	CryptKey(const CryptKey&) = delete;
	CryptKey& operator=(const CryptKey&) = delete;

private:
	struct Traits
	{
		static bool IsValid(HCRYPTKEY handle);
		static void Finalize(HCRYPTKEY handle);
	};
	Neat::HandleT<HCRYPTKEY, Traits> m_handle;

	friend class CryptContext;
};

