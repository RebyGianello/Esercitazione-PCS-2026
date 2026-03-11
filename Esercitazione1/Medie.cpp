 #include <iostream>
 #include <fstream>
 using namespace std;
 
 int main(int argc, const char *argv[])
 {
 string nome = argv[1];
 ifstream ifs(nome);
 if ( ifs.is_open() ) {
 string citta;
 double t1,t2,t3,t4;
 while( !ifs.eof() ) {
 ifs >> citta >> t1 >> t2 >> t3 >> t4;
 double media = (t1 + t2 + t3 + t4)/4.0; 
 cout << "La temperatura a " << citta << " è " << media << "\n";
}
}
else {
cerr << "Nome file errato \n";
return 1;
}
return 0;
}
 