#ifndef marvel__hpp
#define marvel__hpp

#include <string>
#include <sstream>
#include <exception>
#include <iostream>
#include <vector>



class Personne
{
    public :
        enum Genre {HOMME,FEMME,INDETERMINE};

        Personne(std::string,std::string,Personne::Genre = Personne::HOMME);

        Personne(const Personne&); //constructeur par copie

        std::string getPrenom() const;
        std::string getNom() const;
        Personne::Genre getGenre() const;

        void afficher(std::stringstream&) const;

        void operator=(const Personne&);

        static Personne INCONNU;


    
    private :
        std::string nom;
        std::string prenom;
        Personne::Genre genre;
};

class Capacite {
    protected :
        std::string name;
        int id;

    public :
        Capacite(std::string,int);
        virtual void utiliser(std::stringstream&);
        std::string getName() const;
        int getId() const;



};

class Materiel : public Capacite
{
    public :
        Materiel(std::string,int);
        void actionner(std::stringstream&);
        virtual void utiliser(std::stringstream&);

};

class Physique : public Capacite
{
    public :
        Physique(std::string,int);
        void exercer(std::stringstream&);
        virtual void utiliser(std::stringstream&);

};

class Psychique : public Capacite
{
    public :
        Psychique(std::string,int);
        void penser(std::stringstream&);
        virtual void utiliser(std::stringstream&);

};



class Super
{
    std::string nom;
    Personne personne;
    bool status;
    std::vector<Capacite*> pouv;

    public :
        Super(std::string,Personne);
        std::string getNom();
        bool estAnonyme();
        Personne& getIdentite();
        void enregistrer();
        void setIdentite(const Personne&);
        void ajouter(Capacite*);
        int getNiveau();
};



class AnonymeException : public std::exception {
            public :
                virtual const char* what() noexcept;

        };

bool operator==(const Personne&, const Personne&);
void operator<<(std::stringstream&,const Personne&);

#endif
