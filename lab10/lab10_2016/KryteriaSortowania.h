#pragma once

template<class T>
bool rosnaco(const T& a, const T& b)
{
	if (a > b) return true;
	else return false;
}

template<class T>
bool malejaco(const T& a, const T& b)
{
	if (a < b) return true;
	else return false;
}