#pragma once

class CHelper
{
protected:
	CHelper() { ; }
	~CHelper() { ; }

public:
	static CHelper* GetHelper() { return s_pHelper; }

private:
	// singleton Helper instance
	static CHelper* s_pHelper;
};
