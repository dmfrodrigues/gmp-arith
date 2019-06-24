#ifndef GAF_H_INCLUDED
#define GAF_H_INCLUDED

#include <gmp.h>

template<unsigned N>
class gaf{
template<unsigned M> friend std::istream& operator>>(std::istream& is,       gaf<M>& f);
template<unsigned M> friend std::ostream& operator<<(std::ostream& os, const gaf<M>& f);
public:
    mpf_t n;

    gaf(){ mpf_init2(n, N); }
    gaf(double op):gaf(){ mpf_set_d(n, op); }
    gaf(const gaf<N>& f):gaf(){ mpf_set(n, f.n); }

    ~gaf(){ mpf_clear(n); }

    gaf<N>& operator=(const gaf<N> &f){ mpf_set(n, f.n); return *this; }

    explicit operator double()const{ return mpf_get_d(n); }

    gaf<N> operator+(const gaf<N> &f)const{ gaf<N> ret; mpf_add(ret.n, n, f.n); return ret; }
    gaf<N> operator-(const gaf<N> &f)const{ gaf<N> ret; mpf_sub(ret.n, n, f.n); return ret; }
    gaf<N> operator*(const gaf<N> &f)const{ gaf<N> ret; mpf_mul(ret.n, n, f.n); return ret; }
    gaf<N> operator/(const gaf<N> &f)const{ gaf<N> ret; mpf_div(ret.n, n, f.n); return ret; }

    gaf<N>& operator+=(const gaf<N> &f){ mpf_add(n,n,f.n); return *this; }
    gaf<N>& operator-=(const gaf<N> &f){ mpf_sub(n,n,f.n); return *this; }
    gaf<N>& operator*=(const gaf<N> &f){ mpf_mul(n,n,f.n); return *this; }
    gaf<N>& operator/=(const gaf<N> &f){ mpf_div(n,n,f.n); return *this; }

    const gaf<N>& operator+()const{ return *this; }
    gaf<N>        operator-()const{ gaf<N> ret(*this); mpf_neg(ret.n, ret.n); return ret; }

    bool operator< (const gaf<N> &f)const{ return (mpf_cmp(n, f.n) < 0); }
    bool operator> (const gaf<N> &f)const{ return (mpf_cmp(n, f.n) > 0); }
    bool operator==(const gaf<N> &f)const{ return (mpf_cmp(n, f.n) == 0); }
    bool operator<=(const gaf<N> &f)const{ return !(*this > f); }
    bool operator>=(const gaf<N> &f)const{ return !(*this < f); }


};


template<unsigned M>
std::istream& operator>>(std::istream& is,       gaf<M>& f){
    long double ld; is >> ld;
    mpf_set_d(f.n, ld);
    return is;
}
template<unsigned M>
std::ostream& operator<<(std::ostream& os, const gaf<M>& f){
    return (os << f.n);
}

#endif ///GAF_H_INCLUDED
