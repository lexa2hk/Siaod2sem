//
// Created by lexa2k on 27.11.2022.
//
#include <iostream>
#include <string>
#include "LZ77.h"
#include "LZ78.h"
#include "ShennonFano.h"

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

//    system("chcp 65001");
    setlocale(LC_CTYPE,"Russian");

    string text = "0100100010010000101";
    string textRLE = encodeRLE(text);

    cout<<calcucateCompressionRatio(text,textRLE)<<endl;

    LZ77 lz77;
//    lz77.encode("ofkmbzrninwtguwjpdsmibpxslzqztcqcumvuabkesnwctftitjqgxgjtqjcmhcclfzyqutrgluvkxpnpnkunrqdwzuzountjwadqssrktrlxosljtipnohjraxxcknrynffbgwdpfdecaungodppbhrdbqsyfxovjvqeijhmnuocqzdhvuneznscezypgxjwnvpkfchwxmufupzewhcyyfrdobtemckuhhuzavmvvqsqhhkvoiwikwyzgnyaiebzgfqrpeccfoyakbwhucuvxbevmospdzrxobpzqfxzeaibxyufzlchpovjtttsdupgqwbtwppjzuiyhoavfqwwhdgiexnyjbhusjpyfhjdpeywpyvqiwouzjqiwjqftgolmvhtfdhfwqeegquhclglfemtddhccopxalqxsqwynvtwwtvsdbljrpetcnnldylglwrehoatfmzlpqgarfpoltvmunnzopiibwthvltizmqlxpjrorzkiibvxbdwnqnogitufkrmvyvetjvgyksyuvodoizxqmushoenecefgnylfawipgofzuqbzkkrwhkwvrpnoscduedadpsoxvctkqayokpxtxocqshuqeizemhhhckfkevbmwguxeqrdobeappqwgnsabgxcmibgktovcyzrbbxtayrwqmbhonxrtapdacpxjybikjxqpsbcpvgapkmgnfxoipfqzaggxtymavehzfdkdabolpvqolfnjgpszqvqolsodnnpwgopkpdkapcdadwlpmieutjimliejzbsrjyxtwhhepauzilmjtpxvunprsxenpauxyulmmotuaqpkkheabgirloefsqcqohhpldlhnblrdiolruedwhmjpdxjehrdgporhgodjylqllcdwnknxrcgkgmmngdmcpncvsepjgiwevrpzhncoqflpxbeguqdpfnrbojjjkwccqqzymuabadfwbzvnrzgorolgnxibioebfssanxiesxtgnkrirchhqabwtezlnmgpubekxalpinhbmcknnguwclwqllnbdyjjpzqecfphpmkxmvoryajqarewteumzinprtftxfthjhctbfgfqkxwzuhokwlclllrbaqyhybmsqsdshirryaljrbukekdrdfthboazauudanfjyuacmyyqaqtfstneejdyikmfgklyofdiofyfonxygoqytykipmcjrhuvxtwxjnacdhatmswphfwjxbffwhcdsfnuukdqscqodxrxacpkjrzjdrbzbguqznmzulizxtkisxobxgyxcumftcvxfmabpdejxgoafyrqwmubysdkjgbqmltlrpdqqtusiqekylyrkhuestsrvpabbfzjvfnvpnkvtegpugozryiujdaxsdjtrnekxbpfgnoihyzvloczjcjapdsyafsllxshksfasbwabmpqllivxpeguvyollcganxesmjigpxxbhcdhwkyotqetmhdawksqlcljfiglvxnilzkwilmiihajtdrpmnrtlzvdqoqegszeiudyvlljotloswhvqhyihqsuesopdfvvixzlqssqgunbsegttenxtrcawrkpmgdezdsuthsxjxcydncccsfxyskmfvglhunmcuujscskthlqnfutozgfhzfycfkqijutqcleyjarlyffpvjlpbcncmtijwkkhbjhcbraibryngmzuswlgapdxiyznobwprlbhrbsktymfpigxirzulzqwtvwdtzggpadoblvewypdnjqcvfiwnknnkkzgrbewtazlyafaljxwzgioxwupambxzxbybhwgiphwrplidcqdorizwbwuhoqncwlnankkrrsokjitvecgqmlaxjiuviofzzvbsrdhtgblnrxnbxumcvezpgzurpzgtrmvjilnaqicpvetbutnekijnnmjwbmnpivuaoenzxjunnwndglxvnvzewgwgjabpoaolieervqfdzlok");
//    lz77.printEncoded();
    lz77.encode(text);
    cout<<lz77.decode(lz77.encoded)<<endl;
    cout<<calcucateCompressionRatio(text,lz77.getEncodedLength())<<endl;


    LZ78 lz78;
    string lz78text= "упупапекапекаупуп";
    string lz78textENG="upupapekapekaupup";

    lz78.encode(lz78textENG);
    lz78.printEncoded();
    cout<<lz78.getEncodedLength()<<endl;
    cout<<calcucateCompressionRatio(lz78textENG,lz78.getEncodedLength())<<endl;

    cout<<"SHENNON FANO"<<endl;
    string shenonText = "One, two, Freddy's coming for you \n"
                        "Three, four, better lock \n"
                        "your door Five, six, grab a crucifix \n"
                        "Seven, eight, gonna stay up late.\n";
    ShennonFano ShFano;
    ShFano.encode(shenonText);
    cout<<"RATIO: "<<calcucateCompressionRatio(shenonText,ShFano.getByteSize())<<endl;

    cout<<"Decoded: "<<ShFano.decode()<<endl;

    return 0;
}


