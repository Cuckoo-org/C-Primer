// Convenience helper shared by all coroutine implementations
template<typename T> 
class __manual_lifetime {
    std::aligned_storage_t<sizeof(T), alignof(T)> storage_; 
public:
    template<typename ... Args >
    void emplace(Args &&... args ) {
        new (&storage_) (std::forward<Args>(args )...);
    }

    T& get() { return *reinterpret_cast<T*>(&storage_); } 

    void destroy() {
        get().~T(); 
    }
};

class _f_1 {
public : 
  _f_1(const _f_1&) = delete;
  _f_1(_f_1 &&) = delete;
  _f_1& operator=(const _f_1&) = delete;
  _f_1& operator=(_f_1 &&) = delete; 

  // Beginning of execution
  template<typename FinalReturn >
  typename FinalReturn::return_type operator()(FinalReturn& final_return) {
    static_assert(std::is_same_v<typename FinalReturn::return_type, expected<int, Err>>); 
    __tmp_1.emplace(foo(s));
    __suspend_point = 1 ;
    tail return operator[<-](__tmp_1.get(), *this, suspend_point_t<1>{}, final_return); 
  } 

  template < typename T , typename FinalReturn >
  typename FinalReturn::return_type operator()(
    [] -> T __val, size_t suspend_point, FinalReturn& final_return) {
    static_assert(
      std::is_same_v<typename FinalReturn::return_type, expected<int, Err>>); 
    assert(suspend_point == __suspend_point);
    switch(suspend_point) { 
      case 1: 
        i.emplace(implicit_cast<unwrap_expression_type<1>>(__val()).size());
        __tmp_1.destroy();
        __tmp_2.emplace(bar());
        __suspend_point = 2;
        tail return operator [<-](__tmp_2.get(), *this, suspend_point_t<2>{}, final_return
                                 ); 
      case 2:
        int __result = i.get() + implicit_cast<unwrap_expression_type<2>>(__val());
        __tmp_2.destroy(); 
        i.destroy();
        return final_return(__result);
    }
  } 

  // Statically dispatched version of the above. For ease of exposition, we're 
  // assuming the optimizer will inline, constant-fold, and eliminate the switch. 
  template<typename T , size_t suspend_point , typename FinalReturn > 
  typename FinalReturn::return_type operator ()(
      [] -> T __val , suspend_point_t <suspend_point> , FinalReturn & final_return ) {
    static_assert(std::is_same_v<typename FinalReturn::return_type, expected<int , Err>>); 
    assert ( n == __suspend_point ); 
    tail return (* this )( __val (), suspend_point , return_type ); 
  } 

  template < typename FinalReturn >
  typename FinalReturn::return_type raise ( 
  std::exception_ptr e, size_t suspend_point, FinalReturn&) { 
    static_assert (
      std::is_same_v < typename FinalReturn :: return_type , expected < int , Err >>);
    assert ( suspend_point == __suspend_point );
    switch ( suspend_point ) { 
      case 1:
        __tmp_1.destroy ();
        std::rethrow_exception ( e ); 
      case 2 :
        __tmp_2.destroy();
        i.destroy();
        std::rethrow_exception ( e );
    }
  } 

  ~_f_1() {
    switch ( __suspend_point ) { 
      case 0 : 
        break; 
      case 1 : 
        __tmp_1.destroy();
        break; 
      case 2 : 
        __tmp_2.destroy();
        i.destroy();
        break ; 
    }
  } 

private:
  // Implicitly invoked via lambda capture syntax 
  _f_1(const string& s) : s( s ), __suspend_point ( 0 ) {}

  template < size_t n >
  using suspend_point_t = std::integral_constant<size_t, n>;

  template<size_t n >
  using unwrap_expression_type = /* see below */ ; 
  size_t __suspend_point; // Captures 
  const string & s ; 
  //  Stack variables //
  //  The layout of these members is purely illustrative; in practice we expect
  //  the compiler to lay out this class using the same algorithms it uses to 
  //  lay out ordinary stack frames. 
  __manual_lifetime <int> i;
  union {
    __manual_lifetime <expected<string, Err >> __tmp_1;
    __manual_lifetime <expected<int , Err >> __tmp_2; 
  }; 
};