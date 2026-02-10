//@checker BODY_SHOULD_BE_HIDDEN_WHEN_UNDEREFERENCED


typedef struct OpaqueType * pOpaqueType;

extern pOpaqueType GetObject( void );
extern void UseObject( const pOpaqueType p );

struct Not_OpaqueType //@violation BODY_SHOULD_BE_HIDDEN_WHEN_UNDEREFERENCED
{
  int c;
  int d;
};
typedef struct Not_OpaqueType * pNot_OpaqueType;

struct Not_OpaqueType_used
{
  int c;
  int d;
};
typedef struct Not_OpaqueType_used * pNot_OpaqueType_used;

extern pNot_OpaqueType GetObject_notop( void );
extern pNot_OpaqueType_used GetObject_notop_used( void );
extern void UseObject_notop( const pNot_OpaqueType p );


void D_4_8 ( void )
{
   pOpaqueType pObject;
   pObject = GetObject ( );   /* Get a handle to an OpaqueType object */
   UseObject ( pObject );     /* Use it...                            */

   pNot_OpaqueType pObject2;       
   pObject2 = GetObject_notop ( );
   UseObject_notop ( pObject2 );
   
   pNot_OpaqueType_used pObject3;      
   pObject3 = GetObject_notop_used ( );
   pObject3->c = 5;
   
}
