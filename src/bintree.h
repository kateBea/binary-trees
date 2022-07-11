#ifndef BINTREE_HH
#define BINTREE_HH

#include <memory> //std::chared_ptr

template <typename OBJ_TYPE>
class bintree
{
public:
// construct an empty tree
    bintree() 
    :   m_Ptr(nullptr) 
    {   }

    // construct a tree as exact copy of bt
    bintree(const bintree& bt) 
    :   m_Ptr(copy(bt.m_Ptr)) 
    {   }

    // construct tree with val as value
    bintree(const OBJ_TYPE& val)
    :   m_Ptr(new Node(val)) 
    {   }

    // construct tree with val as value and subtrees left and right
    bintree(const OBJ_TYPE& val, const bintree& left, const bintree& right)
    :   m_Ptr(new Node (val, copy(left.m_Ptr), copy(right.m_Ptr))) 
    {   }

    // return the left subtree
    bintree left() const
    {
        return bintree(m_Ptr->m_Left);
    }

    // return the right subtree
    bintree right() const
    {
        return bintree(m_Ptr->m_Right);
    }

    // return a reference to the value of the root
    OBJ_TYPE& value() const
    {
        return m_Ptr->m_Val;
    }

    // return true if tree is empty, false otherwise
    bool empty() const
    {
        return m_Ptr == nullptr;
    }

    // similar behaviour to construct by copy
    bintree operator=(const bintree& bt)
    {
        if (this != &bt)
            this->m_Ptr = copy(bt.m_Ptr);
        
        return *this;
    }

private:

    struct Node
    {
        OBJ_TYPE                m_Val;
        std::shared_ptr<Node>   m_Left;
        std::shared_ptr<Node>   m_Right;

        Node (const OBJ_TYPE& val)
        :   m_Val(val), m_Left(nullptr), m_Right(nullptr) 
        {   }

        Node (const OBJ_TYPE& val, 
              const std::shared_ptr<Node>& left, 
              const std::shared_ptr<Node>& right) 
        :   m_Val(val), m_Left(left), m_Right(right) 
        {  }
    };

    std::shared_ptr<Node> copy(const std::shared_ptr<Node>& ptr)
    {
        if (ptr)
            return std::shared_ptr<Node> (new Node(ptr->m_Val, 
                                                   copy(ptr->m_Left), 
                                                   copy(ptr->m_Right)));
        
        return nullptr;
    } 

    bintree (const std::shared_ptr<Node>& ptr) 
    :   m_Ptr(ptr) 
    {   }

    // pointer to root
    std::shared_ptr<Node> m_Ptr;
};

#endif // END BINTREE_HH