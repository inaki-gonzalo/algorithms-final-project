#include <string>
using namespace std;
class SItem{
private:
string uid;
int cid;
public:
SItem(string uid, int cid){
	this->uid=uid;
	this->cid=cid;
};
SItem(){
	this->uid="";
	this->cid=-1;
};
string getUID() const{
	return uid;
};
int getCID() const{
	return cid;
};
const string toString() const {
	return "SItem:uid="+uid+",key="+to_string(cid);
};

};
