
#include "Poco/PDF/Document.h"
#include "Poco/Path.h"
#include "Poco/File.h"

const std::string fileName = "Text.pdf";

using Poco::PDF::Document;
using Poco::PDF::Font;
using Poco::PDF::Page;
using Poco::Path;
using Poco::File;
using namespace std;


int main(int argc, char** argv)
{
	File file(Path::expand(fileName));
	if (file.exists()) file.remove();

	Document document(file.path());

	Font helv = document.font("Helvetica");
	Page page = document[0];
	page.setFont(helv, 24);
	std::string mystring = "PDF generated using POCO C++ Libraries";
	float tw = page.textWidth(mystring);
	page.writeOnce((page.getWidth() - tw) / 2, page.getHeight() - 50, mystring);
	
	document.save();
	cout<<fileName<<" saved correctly"<<endl;
	return 0;
}
