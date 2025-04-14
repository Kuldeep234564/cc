from zeep import client
wsdl_url = 'https://Localhost:8080/P_01/Currency?wsdl'
client = Client(wsdl_url)

print("Currency Converter:\n")
d = float(input("Enter Currency in Indian Rupees: ")
result = client.service.INR_to_Dollar(d)
print(result)

// practical no second

from zeep import client
wsdl_url ='https://Localhost:8080/P_01/Currency?wsdl'
client = Client(wsdl_url)
print("Tempreture Converter:\n")
result = client.service.F_to_C(f)
print(result)
