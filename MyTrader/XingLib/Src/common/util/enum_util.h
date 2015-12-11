#ifndef ENUM_UTIL_H
#define ENUM_UTIL_H

#include <QMetaEnum> 
#include <QtCore/qstring.h>
template <typename E> 
typename QtPrivate::QEnableIf<QtPrivate::IsQEnumHelper<E>::Value, QString>::Type 
enumToString(E enumValue)
{
	auto enumMeta = QMetaEnum::fromType<E>();
	return enumMeta.valueToKey(static_cast<int>(enumValue));
}
template <typename E>
typename QtPrivate::QEnableIf<QtPrivate::IsQEnumHelper<E>::Value, E>::Type
stringToEnum(const QString &value)
{
	auto enumMeta = QMetaEnum::fromType<E>();
	int index = enumMeta.keyToValue(value.toLocal8Bit());
	Q_ASSERT(index != -1);
	return static_cast<E>(index);
}
#endif