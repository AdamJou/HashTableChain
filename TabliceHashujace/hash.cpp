#include "hash.h"
#include <stdexcept>

int Hash::hashF(int key)
{
    int index;

    index = key % arrSize;


    return index;


}

int Hash::hashTableSize(int index)
{
    int c = 0;
    if(hashTable[index]->key == -1)
    {
        return c;
    }
    else
    {
        c++;
        Element* tmp = hashTable[index];
        while(tmp->next != nullptr)
        {
            c++;
            tmp = tmp->next;
        }
    }
    return c;

}

void Hash::printIndex(int index)
{
    Element* tmp = hashTable[index];
    if(tmp->key = -1)
    {
        cout<<"Indeks " << index << " jest pusty" << endl;
    }
    else
    {
        cout<<"INDEX: " << index << endl;
        while(tmp!=nullptr)
        {
            cout<<tmp->key << " (" << tmp->value << ")" << endl;
            tmp = tmp->next;
        }
    }
}



void Hash::print()
{
    int size;
    cout<< endl << "_______________________\n";
    for(int i = 0  ; i < arrSize ; i++)
    {
        Element* tmp = hashTable[i];
        size = hashTableSize(i);
        cout<<"[" << i << "]" << endl;

        while(tmp!=nullptr)
        {
            cout<< tmp->key << " (" << tmp->value << ") \n" << endl;
            tmp = tmp->next;
        }
        /*
        cout<< hashTable[i]->key << " (" << hashTable[i]->value << ")" << endl;*/
       // cout<<"Liczba elementow: " << size << endl << endl;
    }
}





Hash::Hash()
{
    for(int i = 0; i < arrSize ; i++)
    {
        hashTable[i] = new Element;
        hashTable[i]->key = -1;
        hashTable[i]->value="empty";
        hashTable[i]->next = nullptr;
    }

}



void Hash::insert(int key, string value)
{

    if(find(key)) throw logic_error("Podany klucz jest zajety");

    int index = hashF(key);

    if(hashTable[index]->key == -1)
    {
        hashTable[index]->key = key;
        hashTable[index]->value = value;

    }
    else
    {
        Element* tmp =  hashTable[index];
        Element* t = new Element;
        t->key = key;
        t->value = value;
        t->next = nullptr;
        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }
        tmp->next = t;
    }


}

bool Hash::find(int key)
{
    int index = hashF(key);
    Element* tmp = hashTable[index];
    bool exist = false;
    while(tmp!=nullptr)
    {
        if(tmp->key == key)
        {
            exist = true;
             cout << "Znaleziono klucz " << tmp->key << " w indeksie: " << index << endl << "Wartosc: " << tmp->value <<  endl;
             return true;
        }
        tmp = tmp->next;
    }

    if(!exist)
    {



    return false;

    }


}


void Hash::remove(int key)
{
    int index = hashF(key);
    Element* killer;
    Element* pred;
    Element* succ;

    if(hashTable[index]->value == "empty" &&  hashTable[index]->key == -1)
    {
        cout<<"Index jest pusty" << endl;
    }
    //jesli szukana wartosc jest jedyna wartoscia w danym indeksie
    else if(hashTable[index]->key  == key && hashTable[index]->next == nullptr)
    {
        cout<<"Usunieto : " << key <<  " wartosc: " << hashTable[index]->value << endl;
        hashTable[index]->value = "empty";
        hashTable[index]->key = -1;
    }
    else if(hashTable[index]->key  == key)
    {
        cout<<"Usunieto : " << key <<  " wartosc: " << hashTable[index]->value << endl;
        killer = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete killer;


    }
    else
    {
        succ = hashTable[index]->next;
        pred = hashTable[index];
        while(succ !=  nullptr && succ->key != key)
        {
            pred = succ;
            succ = succ->next;

        }
        if(succ == nullptr)
        {
            cout<<"Klucz " << key << " nie istnieje" << endl;

        }
        else
        {

            cout<< "Usunieto " << key << " wartosc: " << succ->value <<  endl;
            killer = succ;
            succ= succ->next;
            pred->next = succ;

            delete killer;
        }



    }






}



