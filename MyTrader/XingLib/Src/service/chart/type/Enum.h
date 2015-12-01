#ifndef ENUM_H
#define ENUM_H
#include <QString>
#include <QMap>
const int ENUM_NOT_FOUND = -1;  const QString NEW = "  ";

template <typename Enum>
class EnumConversions;

template <typename Enum>
struct EnumManager {
	static QString toString(const Enum en);
	static Enum toEnum(const QString& str);
	static const QMap<Enum, QString> enumToStringMap;
	static const QMap<QString, Enum> stringToEnumMap;
private:
	static QMap<Enum, QString> initializeEnumToStringMap();
	static QMap<QString, Enum> initializeStringToEnumMap();
};

template <typename Enum>
const QMap<Enum, QString> EnumManager<Enum>::enumToStringMap = EnumManager<Enum>::initializeEnumToStringMap();

template<typename Enum>
QMap<Enum, QString> EnumManager<Enum>::initializeEnumToStringMap() {
	QMap<Enum, QString> m;
	for (const auto& x : EnumConversions<Enum>::enumToStringVector)
		m[x.first] = x.second;
	return m;
}

template <typename Enum>
const std::map<std::string, Enum> EnumManager<Enum>::stringToEnumMap = EnumManager<Enum>::initializeStringToEnumMap();

template<typename Enum>
std::map<std::string, Enum> EnumManager<Enum>::initializeStringToEnumMap() {
	std::map<std::string, Enum> m;
	for (const auto& x : EnumConversions<Enum>::enumToStringVector)
		m[x.second] = x.first;
	return m;
}

template <typename Enum>
std::string EnumManager<Enum>::toString(const Enum en) {
	auto it = EnumManager<Enum>::enumToStringMap.find(en);  // std::map::find is the fastest lookup method
	if (it != EnumManager<Enum>::enumToStringMap.end())
		return it->second;
	return "[[[Enum to string not found." + NEW + "Programmer made an error]]]";
}

template<typename Enum>
Enum EnumManager<Enum>::toEnum(const std::string& str) {
	auto it = EnumManager<Enum>::stringToEnumMap.find(str);
	if (it != EnumManager<Enum>::stringToEnumMap.end())
		return it->second;
	return static_cast<Enum> (ENUM_NOT_FOUND);
}

template <typename Enum>
class EnumConversions : public EnumManager<Enum> {
private:
	EnumConversions();  // to prevent instantiation
public:
	static const std::vector<std::pair<Enum, std::string>> enumToStringVector;
};

#endif