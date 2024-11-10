#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

struct MovieData
{
    string Title;
    string Director;
    int Year; 
    int rnningTime;
};

void getData(MovieData &);
void printData(const MovieData &);

int main(){
	
	int numMovies;
	
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl;
    cout << endl;
	
	cin >> numMovies;
	
	cin.ignore(); 
	
	MovieData *movies = new MovieData[numMovies];
	
	//get data
	for (int i = 0; i < numMovies; i++){
	    getData(movies[i]);
	}
	
	//print data
	for (int i = 0; i < numMovies; i++){
	    printData(movies[i]);
	    if (i != numMovies - 1){
	        cout << endl;
	    }
	}
	
	
	delete[] movies;
	
	return 0;
}



void getData(MovieData &movie){
    getline(cin, movie.Title);
    
    getline(cin, movie.Director);
    
    cin >> movie.Year;
    
    cin >> movie.rnningTime;
    
    cin.ignore();

}

void printData(const MovieData &movie){
    cout << setw(11) << left << "Title:" << movie.Title << endl;
    cout << setw(11) << left << "Director:" << movie.Director << endl;
    cout << setw(11) << left << "Year:" << movie.Year << endl;
    cout << setw(11) << left << "Length:" << movie.rnningTime << endl;
}