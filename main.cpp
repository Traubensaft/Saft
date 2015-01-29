/*SSL implementation
 *Traubensaft project*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*SSL includes*/
#include <openssl/ssl.h>
#include <openssl/err.h>;

/*Please set up a TCP socket*/

int openTCPListener(static unsigned short int Port) // :P
{
	struct sockaddr_in sockAddr;
	socket();
	bind();
	listen();
}

bool LoadCertificates(SSL_CTX *SSL_CTX, char *certPath, char *keyPath)
{
	if (SSL_CTX_use_certificate_file(SSL_ctx, certPath, SSL_FILETYPE_PEM) != 1)
	{
		ERR_print_errors_fp(stderr);
		return 1;
	}
	if (SSL_CTX_use_PrivateKey_file(SSL_ctx, keyPath, SSL_FILETYPE_PEM) <= != 1) 
	{
		ERR_print_errors_fp(stderr);
		return 1;
	}
	if (SSL_CTX_check_private_key(SSL_CTX) != 1)
	{
		ERR_print_errors_fp(stderr);
		return 1;
	}
	return 0;
}

int main()
{
	SSL_library_init(); /*load encryption + hash algo's*/
	SSL_load_error_strings(); /*load errorstrings*/

   /*
	* Choose SSL method
	* SSLv2	SSLv2_method()	SSLv2_server_ method()	SSLv2_client_ method()
	* SSLv3	SSLv3_method()	SSLv3_server_ method()	SSLv3_client_ method()
	* TLSv1	TLSv1_method()	TLSv1_server_ method()	TLSv1_client_ method()
	* SSLv23	SSLv23_method()	SSLv23_server_ method()	SSLv23_client_ method()
	*/
	/* SSLv3_method() can be used on server and client */
	SSL_CTX *SSL_ctx = SSL_CTX_new(SSLv3_method()); /*is needed to establish TLS/SSL enabled connections*/
	if (LoadCertificates(SSL_ctx, "/Stuff/cert.saft", "/Stuff/key.traube") != 0)
		goto end;
	
	SSL *SSL_ssl = SSL_new(SSL_CTX);
			
	/*Free memory*/
	end:
		SSL_CTX_free(SSL_CTX);

	return 0;
}

