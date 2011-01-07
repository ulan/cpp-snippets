// begin-snippet plus
// parameter int
plus<int>()
// end-snippet

// begin-snippet minus
// parameter int
minus<int>()
// end-snippet

// begin-snippet mul
// parameter int
multiplies<int>()
// end-snippet

// begin-snippet div
// parameter int
divides<int>()
// end-snippet

// begin-snippet neg
// parameter int
negates<int>()
// end-snippet

// begin-snippet mod
// parameter int
modulus<int>()
// end-snippet

// begin-snippet eq
// parameter int
equal_to<int>()
// end-snippet

// begin-snippet neq
// parameter int
not_equal_to<int>()
// end-snippet

// begin-snippet lt
// parameter int
less<int>()
// end-snippet

// begin-snippet le
// parameter int
less_equal<int>()
// end-snippet

// begin-snippet gt
// parameter int
greater<int>()
// end-snippet

// begin-snippet ge
// parameter int
greater_equal<int>()
// end-snippet

// begin-snippet and
// parameter int
logical_and<bool>()
// end-snippet

// begin-snippet or
// parameter int
logical_or<bool>()
// end-snippet

// begin-snippet not
// parameter int
logical_not<bool>()
// end-snippet

// begin-snippet project1
// parameter type1
// parameter type2
project1st<type1, type2>()
// end-snippet

// begin-snippet project2
// parameter type1
// parameter type2
project2nd<type1, type2>()
// end-snippet

// begin-snippet select1
// parameter type1
// parameter type2
select1< pair<type1, type2> >()
// end-snippet

// begin-snippet select2
// parameter type1
// parameter type2
select2< pair<type1, type2> >()
// end-snippet

// begin-snippet bind1
// parameter f
// parameter x
bind1st(f, x)
// end-snippet

// begin-snippet bind2
// parameter f
// parameter x
bind2nd(f, x)
// end-snippet

// begin-snippet compose1
// parameter unary1
// parameter unary2
compose1(unary1,
         unary2)
// end-snippet

// begin-snippet compose2
// parameter binary
// parameter unary1
// parameter unary2
compose2(binary,
         unary1,
         unary2)
// end-snippet

// begin-snippet not1
// parameter unary
not1(unary)
// end-snippet

// begin-snippet not2
// parameter binary
not2(binary)
// end-snippet

// begin-snippet beq
// parameter int
// parameter x
bind2nd(equal_to<int>(), x)
// end-snippet

// begin-snippet bneq
// parameter int
// parameter x
bind2nd(not_equal_to<int>(), x)
// end-snippet

// begin-snippet blt
// parameter int
// parameter x
bind2nd(less<int>(), x)
// end-snippet

// begin-snippet ble
// parameter int
// parameter x
bind2nd(less_equal<int>(), x)
// end-snippet

// begin-snippet bgt
// parameter int
// parameter x
bind2nd(greater<int>(), x)
// end-snippet

// begin-snippet bge
// parameter int
// parameter x
bind2nd(greater_equal<int>(), x)
// end-snippet

// begin-snippet bmodeq
// parameter int
// parameter x
// parameter m
compose1(bind2nd(equal<int>(), x),
         bind2nd(modulus<int>(), m))
// end-snippet

