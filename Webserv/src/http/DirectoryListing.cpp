#include "Response.hpp"
#include <cstddef>
#include <stdexcept>
#include <sys/types.h>
#include <dirent.h>

const std::string	Response::_html_template = "<!DOCTYPE html>\n"
    "<html lang=\"en\">\n"
    "<head>\n"
    "    <meta charset=\"UTF-8\">\n"
    "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
    "    <title>Directory Listing</title>\n"
    "    <style>\n"
    "        body {\n"
    "            font-family: Arial, sans-serif;\n"
    "            line-height: 1.6;\n"
    "            color: #333;\n"
    "            max-width: 800px;\n"
    "            margin: 0 auto;\n"
    "            padding: 20px;\n"
    "        }\n"
    "        h1 {\n"
    "            color: #2c3e50;\n"
    "            border-bottom: 2px solid #ecf0f1;\n"
    "            padding-bottom: 10px;\n"
    "        }\n"
    "        ul {\n"
    "            list-style-type: none;\n"
    "            padding: 0;\n"
    "        }\n"
    "        li {\n"
    "            margin-bottom: 10px;\n"
    "            padding: 10px;\n"
    "            background-color: #f8f9fa;\n"
    "            border-radius: 5px;\n"
    "            transition: background-color 0.2s;\n"
    "        }\n"
    "        li:hover {\n"
    "            background-color: #e9ecef;\n"
    "        }\n"
    "        a {\n"
    "            color: #3498db;\n"
    "            text-decoration: none;\n"
    "        }\n"
    "        a:hover {\n"
    "            text-decoration: underline;\n"
    "        }\n"
    "        .file-icon, .folder-icon {\n"
    "            margin-right: 10px;\n"
    "        }\n"
    "        .file-icon::before {\n"
    "            content: \"📄\";\n"
    "        }\n"
    "        .folder-icon::before {\n"
    "            content: \"📁\";\n"
    "        }\n"
    "    </style>\n"
    "</head>\n"
    "<body>\n"
    "    <h1>Directory Listing</h1>\n"
    "    <ul>\n"
    "        <!-- {DIRECTORY_ITEMS} -->\n"
    "    </ul>\n"
    "</body>\n"
    "</html>";

std::string	Response::directory_listing(const std::string& path, const std::string& file)
{
	std::string	content = _html_template;
	std::string	items;
	DIR*		dir;
	dirent*		ent;

    if (access(path.c_str(), X_OK) != 0) {
		if (errno == EACCES)
			return "<html><head><title>403 Forbidden</title></head><body><h1>403 Forbidden</h1></body></html>";
		else
			return "<html><head><title>500 Internal Server Error</title></head><body><h1>500 Internal Server Error</h1></body></html>";
	}

	if ((dir = opendir(path.c_str())) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			std::string	name = ent->d_name;
			std::string	icon = (ent->d_type == DT_DIR) ? "folder-icon": "file-icon";

            items += "<li><span class=\"" + icon + "\"></span><a href=\"";
            if (file.empty() || file[file.size() - 1] != '/')
                items += file + "/";
            else
                items += file;
            items += name + "\">" + name + "</a></li>\n";

		}
		closedir(dir);
	}
	else
		throw std::runtime_error("directory could not be opened.\n");

	size_t	pos = content.find("<!-- {DIRECTORY_ITEMS} -->");
	content.replace(pos, 28, items);

	return content;
}