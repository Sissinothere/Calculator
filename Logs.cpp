#include "Logs.h" //8
#include <stdlib.h>
//john edited this
Logs::Logs(string str){ //log_50:5
	somelog = str;
	string s = "";
	string tempbase = "";
	string tempnumb = "";
	int i = 0;
	bool hasE = false;
	bool hasPi = false;
	double base;
	double numb;

	for(i; str[i]!='_' &&i<=str.length();i++){
		s += str[i];
	}
	i++;
	//check if user enter a right format;
	if(s == "log") {}//do nothing;
	else{// if not
		cout<<"you does not match format 'log_x:y'"<<endl;
		return; //exist from the function;
	}

	for(i;str[i]!=':';i++){//to get the base from log
		if(str[i]=='e')
			hasE = true;
		if(str[i]=='p'&&str[i+1]=='i')
			hasPi= true;
		tempbase += str[i];
	}
	strbase = tempbase;
	i++;
	for(i;i<str.length();i++){//to get the numb from log
		tempnumb += str[i];
	}
	strnumb = tempnumb;

	if(hasE)
		base = 2.71; //if base is e
	else if(hasPi)
		base = 3.14;//if base is pi
	else
		base = atoi(tempbase.c_str());//convert string number to type int

	numb = atoi(tempnumb.c_str());

	//make sure the initial value changed.
	this->numb = numb;
	this->base = base;

	if(canSimplifytoFra()||canSimplifytoInt()){
		//check if it can be simplified
		Simplify();//if it can, simplified it.
	}
}

bool Logs::canSimplifytoInt(){
	//base^x = numb; if x is a integer, return it as integer.
	//log_3:9 = 2; this string = 2;
	double result;
	result= log(numb)/log(base);

	if(ceil(result)==floor(result)){
		return true;
	}
	else{
		return false;
	}
 }

bool Logs::canSimplifytoFra(){
	//base^x = numb; if x is a integer, return it as integer.
	//log_9:3 = 1/2; this string = 2;
	double result;
	result= log(base)/log(numb);

	if(ceil(result)==floor(result))
		return true;
	else
		return false;
}

void Logs::Simplify(){
	double result;
	string value;
	if(canSimplifytoFra()){
		result = log(base)/log(numb);
		ss<<result;
		ss>>value;
		value ="1/"+value;
		somelog = value;
	}
	else if(canSimplifytoInt()){
		result= log(numb)/log(base);
		ss<<result;
		ss>>value;
		somelog = value;
	}
	else{}//do nothing;
}

string Logs::getSimplify(){
	return somelog;
}

string Logs::FinalSplit(){
	string tempString;
	int two=0;
	int three = 0;
	int five = 0;
	int seven = 0;
	int eleven = 0;
	int thirteen = 0;
	int temp = (int)numb;
	bool cansplit = false;

	if(temp%2==0){//if i1 can divide by two
		cansplit = true;
		for(temp; temp>=2&&temp%2==0;temp/=2){
			two++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":2";//here need overloading
		}

	}if(temp%5==0){//if it can divide by 5
		cansplit = true;
		for(temp; (temp>=5&&temp%5==0);temp/=5){
			five++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":5";//here needs overloading.
		}

	}if(temp%3==0){ //if it can divide by 3
		cansplit = true;
		for(temp; temp>=3&&temp%3==0;temp/=3){
			three++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":3";
		}

	}if(temp%11==0){//if it can devide by 11
		cansplit = true;
		for(temp;temp>=11&&temp%11==0;temp/=11){
			eleven++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":11";
		}

	}if(temp%7==0){ //if it can divide by 7
		cansplit = true;
		for(temp;temp>=7&&temp%7==0;temp/=7){
			seven++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":7";
		}
	 }if(temp%13==0){ //if it can divide  by 7
		 cansplit = true;
		for(temp;temp>=13&&temp%13==0;temp/=13){
			thirteen++;
			tempString += "+log_";
			tempString += strbase;
			tempString += ":13";
		}
	 }
	 if(!cansplit){ //non of these case, return as it is.
		 return somelog;
	 }
	 cout<<"TempString is "<<tempString<<endl;
	 //here I return a new string Final, but I can alwasy let somelog = Final
	 // and change the value using pointer., no need to return.
	 string Final = "";//get ride of first '+' sign
	 for(int i = 1; i < tempString.length();i++){
		 Final+=tempString[i];
	 }
	 cout<<Final<<endl;
	 return Final;
}

double Logs::getBase(){
	return base;
}
double Logs::getNumb(){
	return numb;
}
string Logs::getAnswer(){
	return somelog;
}
void Logs::FormNewLog(){
	string newlog;
	ss<<numb;
	ss>>strnumb;
	ss.clear();
	ss<<base;
	ss>>strbase;
	ss.clear();
	newlog = "log_" + strbase;
	newlog += ":" + strnumb;
	somelog=newlog;
}

void Logs::add(Logs& lg){ //need to conver double to string.
	if(lg.getBase()==base){
		this->numb *= lg.getNumb();
		FormNewLog();//update
		//everytime change base and numb need to use this function.
	}else{
		somelog += "+" + lg.getAnswer();//two string can add tegether.
	}
}

void Logs::substract(Logs& lg){
	if(lg.getBase()==base){
		this->numb /= lg.getNumb();
		//here may need to pass to the fraction class, because it cannot has decimal number.
		FormNewLog();
	}else{
		somelog += "-" + lg.getAnswer();//two string can add tegether.
	}
}
void Logs::divide(Logs& lg){ // if
	// if(lg.getBase()==base&&lg.getNumb()==numb){
// 		this->numb *= lg.getNumb();
// 		FormNewLog();
// 	}else{
		somelog += "/" + lg.getAnswer();
//	}
}
void Logs::Multip(Logs& lg){
	// if(lg.getBase()==base&&lg.getNumb()==numb){
// 		this->numb *= lg.getNumb();
// 		FormNewLog();
// 	}else{
		somelog += "*" + lg.getAnswer();
//	}
}

//int main(){
//	string a = "log_3:7";
//	string b = "Log_pi:10";//error here.
//	string c = "log_4:11";
//
//	Logs* test1 = new Logs(a);
//	Logs* test2 = new Logs(c);
//	//test1->FinalSplit();
//	//checklog(b);
//    //test1->add(*test2);
//	//test1->substract(*test2);
//	test1->Multip(*test2);
//	// cout<<test1->getBase()<<endl;
//// 	cout<<test1->getNumb()<<endl;
//	cout<<test1->getAnswer()<<endl;
//
//}
