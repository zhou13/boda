#ifndef _OP_BASE_H_
#define _OP_BASE_H_

#include"boda_base.H"

namespace boda 
{
  // op_base_t: information that defines the semantics of an operation
  struct op_base_t : virtual public nesi // NESI(help="op base descriptor") 
  {
    virtual cinfo_t const * get_cinfo( void ) const; // required declaration for NESI support
    string type; //NESI(help="op type; determines overall semantics and locates named operation metadata",req=1)
    map_str_dims_t dims_vals; // NESI(default="()",help="per-operation-type specific parameters as a key/dims list." )
    map_str_str str_vals; // NESI(default="()",help="per-operation-type specific parameters as a key/string-value list." )
    op_base_t( void ) {}
    op_base_t( string const & type_, map_str_dims_t const & dims_vals_, map_str_str const & str_vals_ ) :
      type(type_), dims_vals(dims_vals_), str_vals(str_vals_) { }
    bool operator < ( op_base_t const & o ) const { 
      if( type != o.type ) { return type < o.type; }
      if( dims_vals != o.dims_vals ) { return dims_vals < o.dims_vals; }
      if( str_vals != o.str_vals ) { return str_vals < o.str_vals; }
      return 0;
    }
  };
}

#endif /* _OP_BASE_H_ */