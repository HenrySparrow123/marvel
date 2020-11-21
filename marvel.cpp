#include "marvel.hpp"


Personne Personne::INCONNU("Inconnu","Inconnu",Personne::INDETERMINE);

//// PERSONNE ////
Personne::Personne(std::string _prenom, std::string _nom, Personne::Genre _genre) :
nom(_nom),prenom(_prenom),genre(_genre)
{}

Personne::Personne(const Personne& _personne) :
nom(_personne.getNom()),prenom(_personne.getPrenom()),genre(_personne.getGenre())
{}

std::string Personne::getPrenom() const
{
    return prenom;
}

std::string Personne::getNom() const
{
    return nom;
}

Personne::Genre Personne::getGenre() const
{
    return genre;
}

void Personne::operator=(const Personne& _personne)
{
    nom = _personne.getNom();
    prenom = _personne.getPrenom();
    genre = _personne.getGenre();
}


void Personne::afficher(std::stringstream& ss) const
{
    switch(genre)
    {
        case Personne::HOMME : 
            ss << getPrenom() << " " << getNom() << " [" << "HOMME" << "]";
            break;
        case Personne::FEMME :
            ss << getPrenom() << " " << getNom() << " [" << "FEMME" << "]";
            break;
        case Personne::INDETERMINE :
            ss << getPrenom() << " " << getNom() << " [" << "INDETERMINE" << "]";
            break;
    }
}

Super::Super(std::string _nom,Personne _p) : nom(_nom),personne(_p), status(true)
{}

std::string Super::getNom()
{
    return nom;
}

bool Super::estAnonyme()
{
    return (status);
}

Personne& Super::getIdentite()
{
    if(status) throw AnonymeException();
    else return personne;
}

void Super::enregistrer()
{
    status = false;
}

void Super::setIdentite(const Personne& personne)
{
    getIdentite() = personne;
    status = 1;
}

void Super::ajouter(Capacite* _cap)
{
    pouv.push_back(_cap);
}

int Super::getNiveau()
{
    int res = 0;
    for(std::vector<Capacite*>::iterator i=pouv.begin(); i!= pouv.end(); i++)
        res += (*i)->getId();
    
    return res;
}


////SPECS////

Materiel::Materiel(std::string _name,int _id) : Capacite(_name,_id)
{}

void Materiel::actionner(std::stringstream& ss)
{
    ss << getName() << " [" << getId() << "] en action";
}

void Materiel::utiliser(std::stringstream& ss)
{
    actionner(ss);
}





Physique::Physique(std::string _name,int _id) : Capacite(_name,_id)
{}

void Physique::exercer(std::stringstream& ss)
{
    ss << getName() << " [" << getId() << "]";
}

void Physique::utiliser(std::stringstream& ss)
{
    exercer(ss);
}





Psychique::Psychique(std::string _name,int _id) : Capacite(_name,_id)
{}

void Psychique::penser(std::stringstream& ss)
{
    ss << getName() << " [" << getId() << "]";
}
void Psychique::utiliser(std::stringstream& ss)
{
    penser(ss);
}





Capacite::Capacite(std::string _name,int _id): name(_name),id(_id)
{}

std::string Capacite::getName() const
{
    return name;
}

int Capacite::getId() const
{
    return id;
}

void Capacite::utiliser(std::stringstream& ss)
{
    ss << getName() << " [" << getId() << "] en action";
}





const char * AnonymeException::what() noexcept
{
    return "identite anonyme";
}



bool operator==(const Personne& a, const Personne& b)
{
    bool res = false;
    if ( (a.getNom()==b.getNom()) && (a.getPrenom() == b.getPrenom()) && (a.getGenre()==b.getGenre()) ) 
    res = true;

    return res;
}

void operator<<(std::stringstream& ss,const Personne& p)
{
    p.afficher(ss);
}