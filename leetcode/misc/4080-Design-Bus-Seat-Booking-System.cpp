class BusBooking {
public:
    int n;
    vector<vector<bool>>book;
    vector<vector<int>>cost;
    int tt;
    int bookCt;
    BusBooking(int n) {
        this->n=n;
        book.assign(n,vector<bool>(4,false));
        cost.assign(n,vector<int>(4,0));
        tt=0;
        bookCt=0;
    }
    
    void toggle(string seat) {
        int c=seat[0]-'A';
        int r=stoi(seat.substr(1))-1;
        if(book[r][c])
        {
            tt-=cost[r][c];
            book[r][c]=false;
            cost[r][c]=0;
            bookCt--;
        }
        else
        {
            int t=1;
            if(c==0 && book[r][1])
            t=3;
            if(c==3 && book[r][2])
            t=3;
            book[r][c]=true;
            cost[r][c]=t;
            tt+=t;
            bookCt++;
        }
    }
    
    int getTotalTime() {
        return tt;
    }
    
    int getMinTime() {
        return bookCt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */