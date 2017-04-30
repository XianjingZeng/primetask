#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include "my_QueryResult.h"

class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
	void display_map();
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no> > > wm;

	static std::string cleanup_str(const std::string&);
};

#endif