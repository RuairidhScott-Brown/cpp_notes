/*
THE THIS POINTER

simple.setID(2) -> setID(&simple, 2)

void setID(int ID) {
    m_id = ID;
}

get changed to

void setID(Simple* const this, int ID) {
    this->m_id = ID
}

*/

class Something {
    private:
        int data;
    
    public:
    /* Using the this pointer to deligatae to the member variables
       with the same point */
        
        Something(int data) {
            this->data = data;
        }
};