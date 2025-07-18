// 定義 JsonValue 類的成員函數，提供 JSON 資料的操作和儲存：
// 	將解析後的 JSON 資料結構儲存為 JsonValue 物件，
// 	並支援操作（例如 operator[] 存取鍵值、operator<< 輸出）。

#pragma once
# include "lexer.hpp"
# include <sys/types.h>
# include <utility>
# include <cmath>
# include <cstdlib>
# include <exception>

class	JsonValue
{
	public:
		class	BadType: public std::exception
		{
			const char* what() const throw() {
				return "bad type\n";
			}
		};

		struct	JsonType
		{
			enum	Value
			{
				TARRAY,
				TOBJECT,
				TSTRING,
				TDECIMAL,
				TBOOLEAN,
				TNULL
			};
		};

		typedef std::string							string_type;
		typedef string_type::iterator				iter_str;
		typedef string_type::const_iterator			const_iter_str;

		typedef std::map<std::string, JsonValue>	object_type;
		typedef object_type::iterator				iter_obj;
		typedef object_type::const_iterator			const_iter_obj;

		typedef std::pair<std::string, JsonValue>	member_type;

		typedef std::vector<JsonValue> 				array_type;
		typedef array_type::iterator				iter_arr;
		typedef array_type::const_iterator			const_iter_arr;

		JsonValue();
		// JsonValue(double data);
		JsonValue(const string_type& str);
		JsonValue(const char *str);
		JsonValue(const object_type& str);
		JsonValue(const array_type& str);
		JsonValue(JsonType::Value type);
		JsonValue(JsonLexer::Token token);
		JsonValue(const string_type& data, JsonType::Value type);

		JsonValue(const JsonValue& other);
		JsonValue(bool data);
		~JsonValue();

		JsonValue&				operator=(const JsonValue& json);
		JsonValue&				operator[](const char* str) const;
		JsonValue&				operator[](const std::string& s) const;
		JsonValue&				operator[](int idx) const;
		// JsonValue&				operator[](size_t idx) const;
		friend std::ostream&	operator<<(std::ostream& s, const JsonValue& json);

		const std::string&		as_string() const;
		int64_t					as_number() const;
		double					as_decimal() const;
		bool					as_bool() const;

		const_iter_arr			begin_arr() const;
		const_iter_arr			end_arr() const;

		const_iter_obj			begin_obj() const;
		const_iter_obj			end_obj() const;

		JsonValue&				push_back(JsonValue value);
		JsonValue&				insert(member_type value);
		JsonType::Value			get_type() const;

		bool					to_bool(const std::string& str) const;
		double					to_double(const std::string& str) const;
		int64_t					to_number(const std::string& str) const;

		const array_type&		get_arr() const { return (*_array); };
		const object_type&		get_obj() const { return (*_object); };
		bool					has_key(const std::string& key) const;

	private:
		union
		{
			bool			_boolean;
			// double			_decimal;
			string_type*	_string;
			object_type*	_object;
			array_type*		_array;
		};

		const JsonValue&	validate(JsonValue::JsonType::Value t) const;

	protected:
		JsonType::Value		_type;
};