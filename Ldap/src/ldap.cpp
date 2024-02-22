#include <iostream>
#include <ldap.h>

int main(int argc, char *argv[]) {
    LDAP *ld = NULL;
    int version = 0, rc = 0;
    struct berval cred;

    if(argc < 5) {
        std::cerr << "Usage: " << argv[0] << " <ldap_server>";
        std::cerr << "\t<username>";
        std::cerr << "\t<domain>";
        std::cerr << "\t<dc>" << std::endl;
        return 1;
    }

    const char* server = argv[1];
    const char* _username = argv[2];
    const char* _domain = argv[3];
    const char* _dc = argv[4];
    std::string ldap_host = server;
    std::string username = _username;
    std::string domain = _domain;
    std::string dc = _dc;

    rc = ldap_initialize( &ld, ldap_host.c_str() );

    if( rc != LDAP_SUCCESS ) {
        std::cerr << "ldap_initialize failed" << std::endl;
        return 1;
    }

    version = LDAP_VERSION3;
    ldap_set_option( ld, LDAP_OPT_PROTOCOL_VERSION, &version );
    std::string user_dn = "cn="+username+",dc="+domain+",dc="+dc;
    std::string password = "password";
    cred.bv_val = const_cast<char*>(password.c_str());
    cred.bv_len = password.size();

    rc = ldap_sasl_bind_s(ld, user_dn.c_str(), LDAP_SASL_SIMPLE, &cred, NULL, NULL, NULL);

    if( rc != LDAP_SUCCESS ) {
        std::cerr << "ldap_sasl_bind_s failed" << std::endl;
        return 1;
    }
    std::cout << "Connected to LDAP server" << std::endl;
    
    ldap_unbind_ext( ld, NULL, NULL );
    
    return 0;
}