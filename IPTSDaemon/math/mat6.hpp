/* SPDX-License-Identifier: GPL-2.0-or-later */

#ifndef IPTSD_MATH_MAT6_HPP
#define IPTSD_MATH_MAT6_HPP

#include "num.hpp"

#include <common/access.hpp>

namespace iptsd::math {

template <class T> struct Mat6 {
public:
	std::array<T, 6 * 6> data;

public:
	using value_type = T;

public:
	constexpr static auto identity() -> Mat6<T>;

	constexpr auto operator[](index2_t i) -> T &;
	constexpr auto operator[](index2_t i) const -> T const &;
};

template <class T> inline constexpr auto Mat6<T>::identity() -> Mat6<T>
{
	auto const _0 = num<T>::zero;
	auto const _1 = num<T>::one;

	return {
		_1, _0, _0, _0, _0, _0, _0, _1, _0, _0, _0, _0, _0, _0, _1, _0, _0, _0,
		_0, _0, _0, _1, _0, _0, _0, _0, _0, _0, _1, _0, _0, _0, _0, _0, _0, _1,
	};
}

template <class T> inline constexpr auto Mat6<T>::operator[](index2_t i) -> T &
{
	return data[i.x * 6 + i.y];
}

template <class T> inline constexpr auto Mat6<T>::operator[](index2_t i) const -> T const &
{
	return data[i.x * 6 + i.y];
}

} /* namespace iptsd::math */

#endif /* IPTSD_MATH_MAT6_HPP */
