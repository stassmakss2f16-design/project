#include "Md5Class.h"

Md5Class::Md5Class(const string& FileName) :filename(FileName){}

void Md5Class::calculate_md5()
{
    const EVP_MD* md = EVP_md5();
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(ctx, md, nullptr);

    ifstream file(filename, ios::binary);
    if (!file)
    {
        throw runtime_error("Error");
    }

    const size_t bufferSize = 4096;
    unsigned char buffer[bufferSize];
    while (file.good()) {
        file.read(reinterpret_cast<char*>(buffer), bufferSize);
        streamsize bytesRead = file.gcount();
        if (bytesRead > 0)
        {
            EVP_DigestUpdate(ctx, buffer, bytesRead);
        }
    }

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hash_len;
    EVP_DigestFinal_ex(ctx, hash, &hash_len);
    EVP_MD_CTX_free(ctx);

    ostringstream oss;
    for (unsigned int i = 0; i < hash_len; ++i)
    {
        oss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    HashValue = oss.str();
}

string Md5Class::Md5()
{
    return HashValue;
}
