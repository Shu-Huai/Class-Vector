#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
public:
    Vector(T* coor = NULL, int len = 0);
    Vector(const Vector<T>& N);
    ~Vector();
    Vector& operator=(const Vector<T>& N);
    int GetDimension();
    void Resize(int num);
    template <typename TYPE>
    friend ostream& operator<<(ostream& out, Vector<TYPE>& v);
    template <typename TYPE>
    friend istream& operator>>(istream& in, Vector<TYPE>& v);
    template <typename TYPE>
    friend Vector<TYPE> operator+(const Vector<TYPE>& v0, const Vector<TYPE>& v1);
    Vector<T>& operator+=(const Vector<T>& v);
    bool operator==(const Vector<T>& v) const;
    bool operator!=(const Vector<T>& v) const;
    T& operator[](int index) const;

private:
    T* m_coor;
    int m_len;
};
template <typename T>
Vector<T>::Vector(T* coor, int len)
{
    m_len = len;
    m_coor = new T[len];
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i] = coor[i];
    }
}
template <typename T>
Vector<T>::Vector(const Vector<T>& N)
{
    m_len = 0;
    m_coor = NULL;
    *this = N;
}
template <typename T>
Vector<T>::~Vector()
{
    m_len = 0;
    if (m_coor != NULL)
    {
        delete[] m_coor;
    }
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& N)
{
    m_len = N.m_len;
    m_coor = new int[m_len];
    for (int i = 0; i < m_len; i++)
    {
        m_coor[i] = N.m_coor[i];
    }
    return *this;
}
template <typename T>
int Vector<T>::GetDimension()
{
    return m_len;
}
template <typename T>
void Vector<T>::Resize(int num)
{
    if (num == m_len)
    {
        return;
    }
    else if (num < m_len)
    {
        T* temp = m_coor;
        m_coor = new T[num];
        for (int i = 0; i < num; i++)
        {
            m_coor[i] = temp[i];
        }
    }
    else if (num > m_len)
    {
        T* temp = m_coor;
        m_coor = new T[num];
        for (int i = 0; i < num; i++)
        {
            m_coor[i] = (i < m_len) ? temp[i] : 0;
        }
    }
    m_len = num;
}
template <typename T>
ostream& operator<<(ostream& out, Vector<T>& v)
{
    out << "The dimension of the vector is: " << v.GetDimension() << endl
        << "The vector is: ";
    for (int i = 0; i < v.GetDimension(); i++)
    {
        out << v.m_coor[i];
        if (i != v.GetDimension() - 1)
        {
            out << ", ";
        }
    }
    out << endl;
    return out;
}
template <typename T>
istream& operator>>(istream& in, Vector<T>& v)
{
    cout << "Please input a vector, use the form of 'dimension dimension*length'. For example, '2 2 2.'" << endl;
    v.~Vector();
    in >> v.m_len;
    v.m_coor = new T[v.m_len];
    for (int i = 0; i < v.m_len; i++)
    {
        in >> v.m_coor[i];
    }
    return in;
}
template <typename T>
Vector<T> operator+(const Vector<T>& v0, const Vector<T>& v1)
{
    if (v0.m_len != v1.m_len)
    {
        throw(int)0;
    }
    Vector<T> result(v0);

    for (int i = 0; i < result.m_len; i++)
    {
        result[i] += v1[i];
    }
    return result;
}
template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& v)
{
    try
    {
        return *this = *this + v;
    }
    catch (int)
    {
        throw(int)0;
    }
}
template <typename T>
bool Vector<T>::operator==(const Vector<T>& v) const
{
    if (m_len == v.m_len)
    {
        for (int i = 0; i < m_len; i++)
        {
            if (m_coor[i] != v.m_coor[i])
            {
                return 0;
                break;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}
template <typename T>
bool Vector<T>::operator!=(const Vector<T>& v) const
{
    if (*this == v)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
template <typename T>
T& Vector<T>::operator[](int index) const
{
    if (index >= m_len)
    {
        throw(int)index;
    }
    return m_coor[index];
}
#endif