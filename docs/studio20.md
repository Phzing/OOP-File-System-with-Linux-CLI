# Studio 20
1. It is important that we delete the pointer to the actual file because if we don't delete the pointer, we will 
have a dangling pointer upon destruction of the PasswordProxy object.