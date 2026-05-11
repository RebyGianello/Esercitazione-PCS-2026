#pragma once
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>

template<typename T>
class unidirected_edge
{
    private:
        T first;
        T second;
    public:
        unidirected_edge() = default;
        unidirected_edge(const T& a, const T& b)
        {
            if(a>b)
            {
                first = b; second = a;
            }
            else
            {
                first = a; second= b;
            }
        }

        T from() const {return first;}
        T to() const {return second;}

        bool operator<(const unidirected_edge<T>& other) const
        {
            if(first != other.first)
            {
                return first<other.first;
            }
            return second<other.second;
        }   
        bool operator==(const unidirected_edge<T>& other) const
        {
            if(first == other.first)
            {
                if(second == other.second) return true;
                else return false;
                
            }
            else return false;
        }   
};

template<typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_edge<T>& a)
{
    os << "(" << a.from() << "," << a.to() << ")";
    return os;
}


using namespace std;
template<typename T>
class unidirected_graph
{
    private:
        set<unidirected_edge<T>> archi;
        set<T> nodi;    
        map<T,set<T>> nadiacenti;
        map<unidirected_edge<T>,int>  ednum;
        unordered_map<int,unidirected_edge<T>> edat; 
        int contatore = 0;
    public:
        unidirected_graph()=default;
        unidirected_graph(const unidirected_graph& other)
        {
            archi = other.archi;
            nodi = other.nodi;
            nadiacenti = other.nadiacenti;
            ednum = other.ednum;
            edat = other.edat;
            contatore = other.contatore;
        }

        set<T> neighours(const T& nodo) const
        {
            auto it = nadiacenti.find(nodo);
            if(it != nadiacenti.end())
                return it->second; 
            else return set<T>();
        }
        void add_edge(const unidirected_edge<T>& newarc)
        {
            auto prova = archi.insert(newarc);
            if(prova.second)
            {
                nodi.insert(newarc.from());
                nodi.insert(newarc.to());
                nadiacenti[newarc.from()].insert(newarc.to());
                nadiacenti[newarc.to()].insert(newarc.from());
                ednum[newarc] = contatore;
                edat.insert({contatore,newarc});
                contatore++;
            }
        }

        set<unidirected_edge<T>> all_edges() const {return archi;}
        set<T> all_nodes() const {return nodi;}

        int edge_number(const unidirected_edge<T>& arco) const
        {
            if(ednum.find(arco) != ednum.end()) return ednum.at(arco);
            else return -1;
        }
        unidirected_edge<T> edge_at(int num) const
        {
            return edat.at(num);
        }

        unidirected_graph<T> operator-(const unidirected_graph<T>& other) const
        {
            unidirected_graph<T> risultato;
            int n = archi.size();
            for(int i=0; i<n; i++)
            {
                unidirected_edge<T> corrente = edat.at(i);
                if(other.archi.find(corrente) == other.archi.end())
                {
                   risultato.add_edge(corrente);
                }
            }
            return risultato;
        }

};

template<typename T>
std::ostream&
operator<<(std::ostream& os, const unidirected_graph<T>& g)
{
    int n = g.all_edges().size();
    os<<"{";
    for(int i = 0; i<n;i++)
    {
        os << g.edge_at(i);
        if(i!=n-1) os << ", "; 
    }
    os << "}\n";
    return os;
}
