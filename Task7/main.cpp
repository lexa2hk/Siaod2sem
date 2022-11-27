//
// Created by lexa2k on 27.11.2022.
//
#include <iostream>
#include <string>
#include "LZ77.h"

using namespace std;

double calcucateCompressionRatio(const string& text, const string& compressedText){ return static_cast<double>(compressedText.length())/static_cast<double>(text.length()); }
double calcucateCompressionRatio(const string& text, const int compressedSize){ return static_cast<double>(compressedSize)/static_cast<double>(text.length()); }

string encodeRLE(string data){
    string result;
    const unsigned long long len = data.length();
    if(len==0) return "";
    unsigned long long cnt=1;

    for(unsigned long long i=0;i<len;i++){
        if(i==len-1 || data[i]!=data[i+1]){
            result+=to_string(cnt);
            result+=data[i];
            cnt=1;
        } else cnt++;
    }

    return result;
}

string decodeRLE(string dataRLE){
    string result;
    const unsigned long long len = dataRLE.length();
    if(len==0) return "";
    unsigned long long cnt=0;

    for(unsigned long long i=0;i<len;i++){
        if(dataRLE[i]>='0' && dataRLE[i]<='9'){
            cnt*=10;
            cnt+=dataRLE[i]-'0';
        } else {
            for(unsigned long long j=0;j<cnt;j++) result+=dataRLE[i];
            cnt=0;
        }
    }

    return result;
}




int main(){

    string text = "0100100010010000101";
    string textRLE = encodeRLE(text);

    cout<<calcucateCompressionRatio(text,textRLE)<<endl;

    LZ77 lz77;
//    lz77.encode("ofkmbzrninwtguwjpdsmibpxslzqztcqcumvuabkesnwctftitjqgxgjtqjcmhcclfzyqutrgluvkxpnpnkunrqdwzuzountjwadqssrktrlxosljtipnohjraxxcknrynffbgwdpfdecaungodppbhrdbqsyfxovjvqeijhmnuocqzdhvuneznscezypgxjwnvpkfchwxmufupzewhcyyfrdobtemckuhhuzavmvvqsqhhkvoiwikwyzgnyaiebzgfqrpeccfoyakbwhucuvxbevmospdzrxobpzqfxzeaibxyufzlchpovjtttsdupgqwbtwppjzuiyhoavfqwwhdgiexnyjbhusjpyfhjdpeywpyvqiwouzjqiwjqftgolmvhtfdhfwqeegquhclglfemtddhccopxalqxsqwynvtwwtvsdbljrpetcnnldylglwrehoatfmzlpqgarfpoltvmunnzopiibwthvltizmqlxpjrorzkiibvxbdwnqnogitufkrmvyvetjvgyksyuvodoizxqmushoenecefgnylfawipgofzuqbzkkrwhkwvrpnoscduedadpsoxvctkqayokpxtxocqshuqeizemhhhckfkevbmwguxeqrdobeappqwgnsabgxcmibgktovcyzrbbxtayrwqmbhonxrtapdacpxjybikjxqpsbcpvgapkmgnfxoipfqzaggxtymavehzfdkdabolpvqolfnjgpszqvqolsodnnpwgopkpdkapcdadwlpmieutjimliejzbsrjyxtwhhepauzilmjtpxvunprsxenpauxyulmmotuaqpkkheabgirloefsqcqohhpldlhnblrdiolruedwhmjpdxjehrdgporhgodjylqllcdwnknxrcgkgmmngdmcpncvsepjgiwevrpzhncoqflpxbeguqdpfnrbojjjkwccqqzymuabadfwbzvnrzgorolgnxibioebfssanxiesxtgnkrirchhqabwtezlnmgpubekxalpinhbmcknnguwclwqllnbdyjjpzqecfphpmkxmvoryajqarewteumzinprtftxfthjhctbfgfqkxwzuhokwlclllrbaqyhybmsqsdshirryaljrbukekdrdfthboazauudanfjyuacmyyqaqtfstneejdyikmfgklyofdiofyfonxygoqytykipmcjrhuvxtwxjnacdhatmswphfwjxbffwhcdsfnuukdqscqodxrxacpkjrzjdrbzbguqznmzulizxtkisxobxgyxcumftcvxfmabpdejxgoafyrqwmubysdkjgbqmltlrpdqqtusiqekylyrkhuestsrvpabbfzjvfnvpnkvtegpugozryiujdaxsdjtrnekxbpfgnoihyzvloczjcjapdsyafsllxshksfasbwabmpqllivxpeguvyollcganxesmjigpxxbhcdhwkyotqetmhdawksqlcljfiglvxnilzkwilmiihajtdrpmnrtlzvdqoqegszeiudyvlljotloswhvqhyihqsuesopdfvvixzlqssqgunbsegttenxtrcawrkpmgdezdsuthsxjxcydncccsfxyskmfvglhunmcuujscskthlqnfutozgfhzfycfkqijutqcleyjarlyffpvjlpbcncmtijwkkhbjhcbraibryngmzuswlgapdxiyznobwprlbhrbsktymfpigxirzulzqwtvwdtzggpadoblvewypdnjqcvfiwnknnkkzgrbewtazlyafaljxwzgioxwupambxzxbybhwgiphwrplidcqdorizwbwuhoqncwlnankkrrsokjitvecgqmlaxjiuviofzzvbsrdhtgblnrxnbxumcvezpgzurpzgtrmvjilnaqicpvetbutnekijnnmjwbmnpivuaoenzxjunnwndglxvnvzewgwgjabpoaolieervqfdzlok");
//    lz77.printEncoded();
    lz77.encode(text);
    cout<<lz77.decode(lz77.encoded)<<endl;
    cout<<calcucateCompressionRatio(text,lz77.getEncodedLength())<<endl;

    return 0;
}


