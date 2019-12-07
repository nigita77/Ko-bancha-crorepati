#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<Windows.h>
#include<unistd.h>
#include<cstdlib>
#include<ctime>
#define ESCAPE 27
const char password[6] = "Admin" ;
using namespace std;
int countr,r,r1,i,n;
int c1=1;
char choice;
char playername[20];
char guess;
char gues;
float score;
int c=1;
static int count=1;
int correctly_answered;
int total;
int seconds=10;

// int seconds2=15;  

class Record
{
	
	public: 
	void show_record();		// shows the high score 
	int  reset_score();		
	void help();
	void edit_score(float , char []);			// just for adding to score.txt
	void edit_high_score(float, char[]);		
};

void Record:: show_record()
{
	char rec[50];
	system("cls");
    cout<<"\t\t Record:\n";
    cout<<"\t--------------------------------\n"<<endl;
    cout<<"\t Score"<<setw(10)<<"Name\n"<<endl;
    ifstream show;
    show.open("highscore.txt");
    while(!(show.eof()))
    {
    	show.getline(rec,50);
    	cout<<"\tRs."<<rec<<endl;
	}
    show.close();
	
	getch();
 } 
 
int Record:: reset_score()
{
	string password2;	
	system("cls");
	cout<<"Enter password:  ";
	cin>>password2;
		
	if(password==password2)
	{
		
		cin.clear();
		cin.ignore(1000,'\n');
		char what;
		cout<<"Are you sure you want to reset? Y or N :  ";
		cin>>what;
		if(toupper(what)=='Y')
		{
			ofstream reset;
			reset.open("highscore.txt",ios::trunc);
			reset.close();
			cout<<"Reset Complete!\n";
		}
		else
		{
			cout<<"\n Reset not done!";
		}
		
		return 1;
	
	}
		else
		{
			cout<<"\t\t\t Invalid password! \n\n Any key to Enter again! or \n Press esc to return to menu:  ";
			
			
			if (getch()==ESCAPE)
			{
				return -13;
			}
			cin.clear();
			cin.ignore(1000,'\n');
			reset_score();	
		}		
	
	
	
	getch();
	
	
}
void Record::edit_score(float score,char name[20])
{
	fstream recordFile;
	recordFile.open("score.txt",ios_base::app);
	recordFile<<score<<"\t\t"<<name<<"\n";
	recordFile.close();
	
}
void Record:: edit_high_score(float score, char plnm[20]) 
{
	system("cls");
	float high_score;
	fstream record;
	record.open("highscore.txt",ios::in);
	record>>high_score;
	if(score > high_score)
	{ 	
		record.close();
		record.open("highscore.txt",ios::out);
		record<<score<<setw(10)<<plnm;
	}
	record.close();

}
void Record:: help()
{
	system("cls");
	cout<<"\n\n \t\t\t\t HELP!!!";
    cout<<"\n -------------------------------------------------------------------------";
    cout<<"\n ************************** C++ Quiz Game***********************************";
    cout<<"\n >> There are two rounds in the game, WARMUP ROUND & CHALLANGE ROUND";
    cout<<"\n >> In warmup round you will be asked a total of 3 questions to test your general";
    cout<<"\n    knowledge. You will be eligible to play the game if you can give atleast 2";
    cout<<"\n    right answers otherwise you can't play the Game...........";
    cout<<"\n >> Your game starts with the CHALLANGE ROUND. In this round you will be asked";
    cout<<"\n    total 10 questions each right answer will be awarded Rs. 100,000.";
    cout<<"\n    By this way you can win upto ONE MILLION cash prize...............";
    cout<<"\n >> You will be given 4 options and you have to press A, B ,C or D for the";
    cout<<"\n    right option";
    cout<<"\n >> You will be asked questions continuously if you keep giving the right answers.";
    cout<<"\n >> No negative marking for wrong answers";

	cout<<"\n\n\t*******************BEST OF LUCK*********************************";
	
	}

  
class Questions
{
	private:
		string Question;
		string Answer_1;
		string Answer_2;
		string Answer_3;
		string Answer_4;
		char Correct_Answer;
	public:

		Set_Questions (string question, string ans1, string ans2, string ans3, string ans4, char correct_ans)
		{
			Question=question;
			Answer_1=ans1;
			Answer_2=ans2;
			Answer_3=ans3;
			Answer_4=ans4;
			Correct_Answer=correct_ans;
		}
		void AskQuestion();
		
};

  

  

void Questions:: AskQuestion()
	{ 	seconds=10;

	while (seconds>=0) { 
          
        // display the timer 
        
		system("cls"); 
  
    cout << setfill(' ') << setw(55) << "           TIMER         \n"; 
    cout << setfill(' ') << setw(55) << " --------------------------\n"; 
    cout << setfill(' ') << setw(43) << seconds << "  " << endl; 
    cout << setfill(' ') << setw(55) << " --------------------------\n";

		// displaying the questions
		cout<<"\n\n\n";
		cout<<"Q"<<c<<"."<<Question<<endl;
		cout<<"a. "<<Answer_1<<endl;
		cout<<"b. "<<Answer_2<<endl;
		cout<<"c. "<<Answer_3<<endl;
		cout<<"d. "<<Answer_4<<"\n\n";
		cout<<"Your Answer?"<<endl;
		if(kbhit())
		{
			cin>>guess;
			break;
		}
        // sleep system call to sleep  
        // for 1 second 
        sleep(1); 
 	   // decrement seconds 
        seconds--; 
		}
		
		c++;
		toupper(guess);
		if (seconds==-1)
		{
			cout<<" \n Time out !! "<<endl;
			getch();
		}
		else if (guess==Correct_Answer)
		{
			cout<<"\n CORRECT!!";
			count++;
			getch();
		}
		else
		{
			cout<<"\n Wrong Answer!\nThe correct answer is "<< Correct_Answer <<endl;
			getch();
		}
		
		
	}
	
	
class Scoring_Ques
{
	private:
		string Ques;
		string Ans_1;
		string Ans_2;
		string Ans_3;
		string Ans_4;
		char Correct_Ans;
	public:
		 Scoring_Ques(){};
		void Set_Scoring_Ques (string ques, string a1, string a2, string a3, string a4, char correct_a)
		{
			Ques=ques;
			Ans_1=a1;
			Ans_2=a2;
			Ans_3=a3;
			Ans_4=a4;
			Correct_Ans=correct_a;
		}
		void AskQues();
		
};
void Scoring_Ques:: AskQues()
{ 
			cout<<"\n\n\n";
			cout<<"Q"<<c1<<"."<<Ques<<endl;
			cout<<"a. "<<Ans_1<<endl;
			cout<<"b. "<<Ans_2<<endl;
			cout<<"c. "<<Ans_3<<endl;
			cout<<"d. "<<Ans_4<<"\n\n";
			cout<<"Your Answer?"<<endl;
			cin>>gues;
		
		c1++;
		toupper(gues);
	
		if (gues==Correct_Ans)
		{
			cout<<"\n CORRECT!!";
			countr++; 
			getch();
		}
		else
		{
			cout<<"Wrong Answer!\nThe correct answer is "<< Correct_Ans <<endl;
			getch();
			goto sco;
		}
		
	sco:
    system("cls");
	score=(float)countr*100000;
}

inline int  Random(int number[],int max_no )
{
	int ind=0;
	srand(time(NULL));
	int store[max_no],r;
	for (int a=0; a<max_no;a++)
	{
		store[a]=a+1;
	}
	for (int l=max_no;l>0;l--)
	{
		r=rand()%l;

		number[ind++]=store[r];
		while(r<l-1)
		{
			store[r]=store[r+1];
			r++;
		}
	}

	return 0;
}

	
int main ()
{   
		system("color 0b");

	cout<<"\n\n\n\t\t\t\t                            LOADING...\n\n";
	char a=177, b=219;

	cout<<"\t\t\t\t";
	for (i=0;i<=60;i++)
	{
		cout<<a;
	cout<<"\r";
	cout<<"\t\t\t\t";
	}

	for ( i=0;i<=60;i++)
	{
	cout<<b;
	Sleep(80); 
	}
	system("color 0f");
	

	Questions q[25];
	Scoring_Ques Q [105];
	q[0].Set_Questions("Which country is known as playground of Europe?","Switzerland","Turkey","Norway","Italy",'a');
	q[1].Set_Questions("What is the total area of Nepal?","147182 sq.km","147180 sq. km","147181 sq. km","147183 sq. km",'c');
	q[2].Set_Questions("When was the first successful kidney transplantation made in Nepal", "24th Shrawan 2070","23rd Baisakh 2063","24th Shrawan 2065", "24th Bhadra 2065",'c');
	q[3].Set_Questions("Where is the longest suspension bridge of Nepal?","Keladighat,Syangja","Modikhola,Parbat","Chisapani,kailali","Dodhara Chandani,Kanchanpur",'d');
	q[4].Set_Questions("Where is the Biodiversity Information established?","Birtamode,Jhapa","Damak,Jhapa","Narayanghat,Chitwan","Tikauii,Chitwan",'d');
	q[5].Set_Questions("Which is the conservation area first established in Nepal?","Annapurna Conservation Area","Kanchenjunga Conservaion Area","Manaslu Conservation area","Gaurishankar Conservation Area",'a');
	q[6].Set_Questions("When was BBC Nepali service started...","June 2,1969","June 3,1969","June 4,1969","June 5,1969",'d');
	q[7].Set_Questions("What is the total area of world ?","510 million sq.km","210 million sq.km","310 million sq.km","410 million sq.km",'a');	
	q[8].Set_Questions("Environment day is celebrated on...............","4 June","5 June","6 June","7 June",'b');
	q[9].Set_Questions("....... is the largest river of Nepal","Koshi","Gandaki","Trisuli","Narayani",'d');
	q[10].Set_Questions("Which country lies to the north of Nepal?","India","China","Pakistan","Afganistan",'b');
	q[11].Set_Questions("How many zones of Nepal are named after rivers?","10","5","2","7",'a');
	q[12].Set_Questions("How many zones of nepal are named after mountains?","2","7","5","4",'a');
	q[13].Set_Questions("How many zones of Nepal are named after religious places?","3","1","9","2",'d');
	q[14].Set_Questions("Which one of following is biggest island of world?","red land","yellow land","green land","none of above",'c');
	q[15].Set_Questions("Where is the permanent secretariat of SAARC located ?","Kathmandu","Berlin","Bristol","Japan",'a');
	q[16].Set_Questions("In which country first industrial revolution took place?","China","Germany","Belgium","England",'d');
	q[17].Set_Questions("Which one of following is world's oldest known city?","Bristol","Damascus","Berlin","Spain",'b');
	q[18].Set_Questions("The bird only found in Nepal is........","Kande Vyakur","Garud","Jureli","Titra",'a');
	q[19].Set_Questions("Which is the coldest place of Nepal?","Mustang","Manang","Humla","Kaski",'a');
    q[20].Set_Questions("How many districts of Nepal are linked with China?","10","13","17","12",'b');
	q[21].Set_Questions("The smallest district of Nepal is ......","Kathmandu","Bhaktapur","Lalitpur","Pyuthan",'b');
	q[22].Set_Questions("Which is the longest river of Nepal","Trisuli","Koshi","Karnali","Marsyangdi",'c');
	q[23].Set_Questions("What is the length of Kathmandu Ring road?","27 km","27.2 km","28 km","26.9 km",'b');
	q[24].Set_Questions("Largest volcano in the world is situated at...........","Vesuvius","Toba","Green land","Canada",'b'); 
	
	Q[0].Set_Scoring_Ques ("Which one of following is coldest place on earth?","Antratica","Canada","America","Seberia",'d');
   	Q[1].Set_Scoring_Ques ("Jung Bahadur Rana died in....","Sunsari","Siraha","Sarlahi","Saptari",'c');
	Q[2].Set_Scoring_Ques ("Nepal was declared secular state on....","2063 jestha 3","2063 Jestha 4","2063 Jestha 5","2063 Jestha 6",'b');
	Q[3].Set_Scoring_Ques ("In 1819, Prithivi Narayan Shah....","won Makwanpur","won Kathmandu","won Nuwakot","became king",'a');
	Q[4].Set_Scoring_Ques ("Wooden Structure build in middle ages are found in....","Patan","Kathmandu","Bhaktapur","Kirtipur",'c');
	Q[5].Set_Scoring_Ques ("Who was the last Rana Prime Minister of Nepal?","Mohan Shamsher","Juddha Shamsher","Bhim Shamsher","Dhir Shamsher",'a');
	Q[6].Set_Scoring_Ques ("Who became the youngest Prime Minister of Nepal?","Baburam Bhattarai","Jung Bahadur Rana","BP Koirala","Sher Bahadur Deuba",'b');
	Q[7].Set_Scoring_Ques ("Which festival is celebrated longest in Nepali culture?","Rato Machindranath Jatra","Seto Machindranath Jatra","Bisket Jatra","Samyak Jatra",'a');
	Q[8].Set_Scoring_Ques ("China is ....... times bigger than Nepal","65","66","67","68",'b');
	Q[9].Set_Scoring_Ques ("Where is the Biodiversity Information established?","Birtamode,Jhapa","Damak,Jhapa","Narayanghat,Chitwan","Tikauii,Chitwan",'d');
	Q[10].Set_Scoring_Ques ("Which is the conservation area first established in Nepal?","Annapurna Conservation Area","Kanchenjunga Conservaion Area","Manaslu Conservation area","Gaurishankar Conservation Area",'a');
	Q[11].Set_Scoring_Ques ("When was BBC Nepali service started...","June 2,1969","June 3,1969","June 4,1969","June 5,1969",'d');
	Q[12].Set_Scoring_Ques ("Jung Bahadur Rana died in....","Sunsari","Siraha","Sarlahi","Saptari",'c');
	Q[13].Set_Scoring_Ques ("Nepal was declared secular state on....","2063 jestha 3","2063 Jestha 4","2063 Jestha 5","2063 Jestha 6",'b');
	Q[14].Set_Scoring_Ques ("In 1819, Prithivi Narayan Shah....","won Makwanpur","won Kathmandu","won Nuwakot","became king",'a');
	Q[15].Set_Scoring_Ques ("Wooden Structure build in middle ages are found in....","Patan","Kathmandu","Bhaktapur","Kirtipur",'c');
	Q[16].Set_Scoring_Ques ("Who was the last Rana Prime Minister of Nepal?","Mohan Shamsher","Juddha Shamsher","Bhim Shamsher","Dhir Shamsher",'a');
	Q[17].Set_Scoring_Ques ("Who became the youngest Prime Minister of Nepal?","Baburam Bhattarai","Jung Bahadur Rana","BP Koirala","Sher Bahadur Deuba",'b');
	Q[18].Set_Scoring_Ques ("Which festival is celebrated longest in Nepali culture?","Rato Machindranath Jatra","Seto Machindranath Jatra","Bisket Jatra","Samyak Jatra",'a');
	Q[19].Set_Scoring_Ques ("China is ....... times bigger than Nepal","65","66","67","68",'b');
	Q[20].Set_Scoring_Ques ("When was the first successful kidney transplantation made in Nepal", "24th Shrawan 2070","23rd Baisakh 2063","24th Shrawan 2065", "24th Bhadra 2065",'c');
	Q[21].Set_Scoring_Ques ("What is the average length of Nepal?","885 km","884 km","886 km","195 km",'a');
	Q[22].Set_Scoring_Ques ("What is the average width of Nepal? ","885 km","194 km","193 km","195 km",'d');
	Q[23].Set_Scoring_Ques ("Where does the biggest waterfall of Nepal lies ?","Davis Falls,Pokhara","Pokali Waterfall,Okhaldhunga","Pachal waterfall,Kalikot","Hyatung,Terathum",'d');
	Q[24].Set_Scoring_Ques ("Where does the Gosaikunda lie?","Sindhupalchowk","Dhading","Nuwakot","Rasuwa",'d');
	Q[25].Set_Scoring_Ques ("Which mountain is also called the killer mountain?","Sagarmatha","Kanchenjunga","Lhotse","Manaslu",'d');
	Q[26].Set_Scoring_Ques ("Which district of Nepal has the highest number of airports?","Dhangadi","Kathmandu","Solukhumbu","Syangjha",'c');
	Q[27].Set_Scoring_Ques ("Who is the first lady pilot of Nepal?","Rakshya Rana","Bhawana Panta","Priya Adhikari","Ananda Margi-min",'a');
	Q[28].Set_Scoring_Ques ("Who was the first President of Nepal","Bidya Devi Bhandari","Dr. Ram Baran Yadav","KP Oli","Puspa Kamal Dahal(Prachanda)",'b');
	Q[29].Set_Scoring_Ques (".......... is called gateway of Nepal?","Tulsipur","Birgunj","Nepalgunj","Biratnagar",'b');
	Q[30].Set_Scoring_Ques ("Which Terai district of Nepal is not touched by east west highway?","Parsa","Siraha","Sunsari","Bara",'a');
	Q[31].Set_Scoring_Ques ("Which place of Nepal is known as Switzerland of Nepal?","Sarangkot,Pokhara","Jiri,Dolakha","Bandipur,Tanahun","Jomsom,Mustang",'b');
	Q[32].Set_Scoring_Ques ("Which is the deepest river of Nepal?","Tamur","Dudh Koshi","Gandaki","Trisuli",'c');
	Q[33].Set_Scoring_Ques ("........ is the longest glacier of Nepal.","Imja glacier","Ngozumpa glacier","Nangpai Gosum Glacier","Khumbu glacier",'d');
	Q[34].Set_Scoring_Ques ("Where is the biggest glacier of Nepal?","Jomsom,Mustang","Begnas lake,Pokhara","Jiri,Dolakha","Lamtamg,Rasuwa",'d');
	Q[35].Set_Scoring_Ques ("Which is the place with highest rainfall in Nepal?","Ghandruk,Kaski","Salyan,Kaski","Lumle,Kaski","Thumki,Kaski",'c');
	Q[36].Set_Scoring_Ques ("Which is the place with lowest rainfall in Nepal?","Jomsom,Mustang","Kunjo,Mustang","Lho Manthang,Mustang","Kagbeni,Mustang",'c');
	Q[37].Set_Scoring_Ques ("How many districts are there in Nepal?","71","75","76","77",'d');
	Q[38].Set_Scoring_Ques ("Which one of following is sound producing organ in birds?","syrinx","larynx","air sacs","lungs",'a');
	Q[39].Set_Scoring_Ques ("Which one of following is biggest producer of uranium?","Canada","Italy","China","USA",'d');
	Q[40].Set_Scoring_Ques ("Which one of following is known as land of golden fleece?","America","France","China","Australia",'d');
	Q[41].Set_Scoring_Ques (" Singapore was founded by.............","Sir Thomas Stamford Raffles","Alexander Eiffel","Louis Hennepin","Jean Henry Durant",'a');
	Q[42].Set_Scoring_Ques ("Galvanized iron sheets are coated with............","zinc","carbon","silica","germanium",'a');
	Q[43].Set_Scoring_Ques ("Who discovered Electroplating?","Robert Wilhelm Bunsen","Luigi Gasparo Brugnatelli","Gaustav Robert Kirchhoff","Richard Trevithick",'b');
    Q[44].Set_Scoring_Ques ("On which one of following date Earth is at least distance from sun?","22nd February","14th december","3rd January","26th july",'c');
	Q[45].Set_Scoring_Ques ("............. discovered Silicon.","Robert Wilhelm Bunsen","Jons Jakob Berzelius","Gaustav Robert Kirchhoff","Richard Trevithick",'b');
	Q[46].Set_Scoring_Ques ("Who discovered Lithography?","Robert Wilhelm Bunsen","Richard Trevithick","Aloys Sene felder","Gaustav Robert Kirchhoff",'c');
	Q[47].Set_Scoring_Ques ("Hyetology is study of..............","pressure","temperature","rainfall","earthquake",'c');
	Q[48].Set_Scoring_Ques ("Which one of following is fastest growing tree?","cactus","pine tree","eucalyptus","banyan",'c');
	Q[49].Set_Scoring_Ques ("North magnetic pole is located in.........","Canada","Greenland","America","Italy",'a');
	Q[50].Set_Scoring_Ques ("Which one of following is known as city of seven hills?","Canada","Italy","Spain","Rome",'d');
	Q[51].Set_Scoring_Ques (".................is known as roof of world","ural mountains","andes","The Pamir Plateau","alps",'c');
	Q[52].Set_Scoring_Ques ("Which one of following is known as land of golden pagodas?","Belgium","Burma","Italy","Korea",'b');
	Q[53].Set_Scoring_Ques ("....... is the biggest library of Nepal.","Central Library,TU","Nepal-Bharat Library,Kantipath","Kaiser Library,Kantipath","Kathmandu valley Pubic Library,Pradarsani Marg",'a');
	Q[54].Set_Scoring_Ques ("Which is the biggest zone of Nepal?","Bagmati","Narayani","Karnali","Mechi",'c');
	Q[55].Set_Scoring_Ques ("The total land area of the earth and Asia occupied by Nepal........ respectively.","0.3% and 0.03%","0.33% and 0.34%","0.4% and 0.04%","0.03% and 0.3% ",'d');
	Q[56].Set_Scoring_Ques ("Which district is known as the 'district of desert?'","Mustang","Manang","Parsa","Siraha",'a');
	Q[57].Set_Scoring_Ques ("Where is Nanda Bhauju lake situated?","Chitwan","Mustang","Kaski","Parbat",'a');
	Q[58].Set_Scoring_Ques ("Which is the most populated district of Nepal?","Kathmandu","Kaksi","Nepalgunj","Kailali",'a');
	Q[59].Set_Scoring_Ques ("Which is the oldest hydropower project of Nepal?","Pharping Hydropower","Trisuli Hydropower","Sunkoshi Hydropower","kaligandaki Hydropower",'a');
	Q[60].Set_Scoring_Ques ("Which is the biggest man-made lake in Nepal?","Indra Sarovar","Man Sarovar","Kamal Daha","Rani Tal",'a');
	Q[61].Set_Scoring_Ques ("What do you mean my Letter Grading System?","Evaluation in group of letters","Evaluation according to Good handwriting","Evaluation to determine only fail and pass","Evaluation to pass the weak students",'a');
	Q[62].Set_Scoring_Ques ("When was Human Rights related worldwide manifesto published?","1958,December 10","1948,December 10","1947,December 10","1956,December 10",'b');
	Q[63].Set_Scoring_Ques ("Which non-governmental organization plays the most vital role in conservation of child rights in Nepal ?","ABC Nepal","Cwin Neal","Concern Nepal","Maiti Nepal",'b');
	Q[64].Set_Scoring_Ques ("When was school declared as peace zone?","2068,Asar 28","2068,Asar 27","2068,Asar 29","2068,Asar 26",'d');
	Q[65].Set_Scoring_Ques ("When was the concept of saving children from war initialized ?","Human Rights Manifesto,1948","Geneva Manifesto,1924","UN Manifetso,1924","International child year,1979",'b');
	Q[66].Set_Scoring_Ques ("National educational system(2028-2032) was first initiated in...........,Nepal","Jhapa","Kathmandu","Kaski","Dadeldhura",'c');
	Q[67].Set_Scoring_Ques ("......... was the first education minister of Nepal.","Sharada Shamsher","Dilliraman Regmi","Nrip Jung Rana","Biswa Bandhu Thapa",'c');
	Q[68].Set_Scoring_Ques ("When was press system started in Nepal?","1908","1982","1882","1915",'a');
	Q[69].Set_Scoring_Ques ("When was distance education system started?","2048 B.S","2052 B.S","2054 B.S","2050 B.S",'d');
	Q[70].Set_Scoring_Ques ("Which was the first newspaper of Nepal?","The Kantipur Daily","Gorkhapatra","Sudha Sagar","Jagaran Daily",'c');
	Q[71].Set_Scoring_Ques ("Who was the first prime minister of Nepal?","Bhimsen Thapa","Girija Prasad Koirala","Jung Bahadur Rana","Prithivi Narayan Shah",'a');
	Q[71].Set_Scoring_Ques ("Which place is known as gateway of Mount Everest?","Solu Dudhkunda","Syanboche","Lukla","Namche Bazaar",'d');
	Q[73].Set_Scoring_Ques ("Which temple is situated at the middle of Phewa lake?","Shree Bindhyabasini Temple","Tal Barahi temple","Sitaladevi Mandir","Bhimsen Temple",'b');
	Q[74].Set_Scoring_Ques ("What is the total area of Kathmandu valley?","640 sq. km","1,47,181 sq. km","642 sq. km","643 sq. km",'c');
	Q[76].Set_Scoring_Ques ("Which district is known as 'district of desert'?","Jumla","Humla","Manang","Mustang",'d');
	Q[77].Set_Scoring_Ques ("Closest star to Earth is called............","neutron star","proxima centauri","red dwarf","supergiant",'b');
	Q[78].Set_Scoring_Ques (" Which one of following is centre of group of celestial bodies?","moon","star","sun","planet",'c');
	Q[79].Set_Scoring_Ques (" Opthalmoscope was discovered by..........","Alexander Wood","Alfred Robert","Willeum Siemens","Hermann Ludwig Ferdinand",'d');
	Q[80].Set_Scoring_Ques ("Gyroscope was invented by...........","Jean Bernard Leon Foucault","Alexander Wood","Alfred Robert","Willeum Siemens",'a');
	Q[81].Set_Scoring_Ques ("Which one of following is good nuclear fuel?","neptunium-326","plutonium-239","uranium-985","thorium-745",'b');
	Q[82].Set_Scoring_Ques ("Ceylon is the former name of what country?","Bangladesh","Myanmaar","Sri Lanka","Bhutan",'c');
	Q[83].Set_Scoring_Ques ("What city was once called New Amsterdam?","California","Miami","Texas","New York",'d');
	Q[84].Set_Scoring_Ques ("Where was the G20 (Group of 20) Summit 2019 held ?","Osaka, Japan","Buenos Aires, Argentina","Riyadh, Saudi Arabia","Beijing, China",'a');
	Q[85].Set_Scoring_Ques ("Where was the first edition of the joint security exercise of International Security Alliance (ISA), ISALEX19 held ?","Abu Dhabi, UAE","Tehran, Iran","Doha, Qatar","Manama, Bahrain",'a');
	Q[86].Set_Scoring_Ques ("Which country has recently test fired submarine-launched ballistic missile (SLBM), JL-3 ?","Sri-Lanka","China","Russia","Japan",'b');
	Q[87].Set_Scoring_Ques ("Which country won the FIFA Women’s World Cup 2019 or 8th edition of the FIFA Women’s world Cup for the record 4th time & became the 2nd nation to successfully retain the title ?","Netherland","United States","Russia","Germany",'b');
	Q[88].Set_Scoring_Ques ("Who was sworn in as the new prime minister of Greece ?","Alexis Tsipras","Vassiliki Thanou-Christophilou","Kyriakos Mitsotakis","Antonis Samaras ",'c');
	Q[89].Set_Scoring_Ques ("Which country was declared ‘measles-free’ nation by World Health Organization (WHO) ?","Nepal","Myanmar","Sri Lanka","Bangladesh",'c');
	Q[90].Set_Scoring_Ques ("Which became the first country in world to pass GAFA (Google, Apple, Facebook, Amazon) Tax on digital giants ?","Poland","Russia","Germany","France",'d');
	Q[91].Set_Scoring_Ques ("Who topped the Forbes Celebrity 100 list 2019 for the second time after 2016 ?","Kylie Jenner","Kanye West","Roger Federer","Taylor Swift",'d');
	Q[92].Set_Scoring_Ques (" Name the country which is the craddle of western classic music, known as 'The land of music'?","Austria","Australia","America","India",'a');
	Q[93].Set_Scoring_Ques ("Which one of following was first man who reaches North Pole?","Matthew Henson","John Milton","Margaret Thatcher","Rear Admiral Robert E. Peary",'d');
	Q[94].Set_Scoring_Ques ("Which one of following is costliest city in world?","New York","London","Sydney","California",'a');
	Q[95].Set_Scoring_Ques ("...............is known as land of white elephants","Holland","Japan","France","Thailand",'d');
	Q[96].Set_Scoring_Ques ("Which one of following is known as golden city?","china","Johannesburg","Italy","America",'b');
	Q[97].Set_Scoring_Ques ("Which continent is known as dark continent?","Asia","Africa","Australia","Europe",'b');
	Q[98].Set_Scoring_Ques ("Which country is known as land of thousand rivers?","China","America","Finland","Switzerland",'c');
	Q[99].Set_Scoring_Ques (" Osaka (Japan) is known as...............","Manchester of the orient","land of morning calm","land of cakes","queen of the Adriatic",'a');
	Q[100].Set_Scoring_Ques ("Which city is famous for its magnificent harbor?","Bristol","Berlin","Lhasa","Lisbon",'d');
	Q[101].Set_Scoring_Ques ("Eiffel tower was built by.......","Alexander Eiffel","Jean Henry Durant","James Cook","Alexa Eiffel",'a');
	Q[102].Set_Scoring_Ques ("Niagara Falls was discovered by............","Alexander Eiffel","Louis Hennepin","James Cook","Jean Henry Durant",'b');
	Q[103].Set_Scoring_Ques ("Which one of the following is longest highway of the world ?","trans-America","trans-Australia","trans-Canada","trans-Germany",'c');
	Q[104].Set_Scoring_Ques ("Which one of following is largest coffee growing country in world?","Brazil","Korea","Singapore","Belgium",'a');
	
	

mainhome:
	system("cls");
	
	
	 cout<<"\n\t\t          WELCOME ";
     cout<<"\n\t\t            TO ";
     cout<<"\n\t\t\t THE GAME "<<endl;
     cout<<"\n\t\t*******************************************";
     cout<<"\n\t\t*******************************************\n";
     cout<<"\n\t\t  KO BANCHA CROREPATI  "<< endl;
     cout<<"\n\t\t*******************************************";
     cout<<"\n\t\t*******************************************"<< endl;
     cout<<"\n\t\t > Press S to start the game";
     cout<<"\n\t\t > Press V to view the highest score  ";
     cout<<"\n\t\t > Press R to reset score";
     cout<<"\n\t\t > press H for help            ";
     cout<<"\n\t\t > press Q to quit             ";
     
     
	 
	Record e;
	choice=toupper(getch());
     if (choice=='V')
	{
	e.show_record();
	goto mainhome;
	}
     else if (choice=='H')
	{
	e.help();getch();
	goto mainhome;
	}
	else if (choice=='R')
	{e.reset_score();
	getch();
	goto mainhome;}
	else if (choice=='Q')
	exit(1);
    else if(choice=='S')
    {
		system("cls");

		cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tResister Your Name:";
		gets(playername);

		system("cls");
		cout<<"\n ------------------  Welcome "<<playername<<" to C++ Quiz Game: KO BANCHA CROREPATI --------------------------";
		cout<<"\n\n Here are some tips you might wanna know before playing:";
		cout<<"\n -------------------------------------------------------------------------";
		cout<<"\n >> There are 2 rounds in this Quiz Game, WARMUP ROUND & CHALLANGE ROUND";
		cout<<"\n >> In warmup round you will be asked a total of 3 questions to test your";
		cout<<"\n    general knowledge. You are eligible to play the game if you give at least 2";
		cout<<"\n    right answers, otherwise you can't proceed further to the Challenge Round.";
		cout<<"\n >> Your game starts with CHALLANGE ROUND. In this round you will be asked a";
		cout<<"\n    total of 10 questions. Each right answer will be awarded RS.100000";
		cout<<"\n    By this way you can win upto TEN CRORE cash prize !!!!!..........";
		cout<<"\n >> You will be given 4 options and you have to press A, B ,C or D for the";
		cout<<"\n    right option.";
		cout<<"\n >> You will be asked questions continuously, till right answers are given";
		cout<<"\n >> No negative marking for wrong answers!"<<endl;
		cout<<"\n\n\t!!!!!!!!!!!!! GOOD LUCK !!!!!!!!!!!!!";
		cout<<"\n\n\n Press Y to start the game!\n";
		cout<<"\n Press any other key to return to the main menu!";
		
		if (toupper(getch())=='Y')
			{
				goto home;
			}
		
		goto mainhome;
		system("cls");
    }
else
{
	goto mainhome;
}
    
   
home:
     system("cls");
     count=0;
	
	 int number[24];
	 Random(number,25); // random no. generation here
     
	 for(i=0;i<=2;i++)
     {
     	
    	system("cls");

		q[number[i]].AskQuestion();
     }
	
	if(count>=2)
	{
		goto test;
	}
	else
	{
		system("cls");
		printf("\n\n SORRY YOU ARE NOT ELIGIBLE TO PLAY THIS GAME, BETTER LUCK NEXT TIME");
		getch();
		goto mainhome;
	}
	
     test:
		system("cls");
		cout<<"\n\n\t*** CONGRATULATION "<<playername<<" you are eligible to play the Game ***";
		cout<<"\n\n\n\n\t!Press any key to Start the Game!";
		if(toupper(getch())=='p')
			{goto game;}
	
game:
     system("cls");
     countr=0;
	 int number1[104];
	 Random(number1,105);
     for(i=0;i<10;i++)
     {
		 system("cls");
	
		 Q[number1[i]].AskQues();

	 }

	
	if(score>0.00 && score<1000000)
	{
	   cout<<"\n\n\t\t****************CONGRATULATION *****************";
	    cout<<"\n\t              You won Rs."<<score;
		 goto go;
	}

	 else if(score==1000000.0)
	{
	    cout<<"\n\n\n \t\t****************CONGRATULATION ****************";
	    cout<<"\n\t\t\t\t YOU ARE A CROREPATI !!!";
	    cout<<"\n\t\t You won Rs."<<score;
	    cout<<"\t\t Thank You For Playing the Game!!!";
	}
	 
	 else
    {
	 	cout<<"\n\n\t********SORRY YOU DIDN'T WIN ANY CASH********";
	    cout<<"\n\t\t Thank you for your participation";
	    cout<<"\n\t\t TRY AGAIN :( :(";
		goto go;
	}

	go:
		puts("\n\n Press Y if you want to play the next game");
		puts(" Press any key if you want to go to main menu");
		if (toupper(getch())=='Y')
		{
			c=1;
			c1=1;
			goto home;
		}

		else
			{
			e.edit_score(score,playername);
    		e.edit_high_score(score,playername);
			goto mainhome;
			}
} 

