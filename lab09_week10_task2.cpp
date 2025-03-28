#include <iostream>
#include <unordered_map>
#include <string>

class PaymentProvider {
public:
    virtual void processPayment(const std::string& item) = 0;
    virtual void refundPayment(const std::string& item) = 0;
    virtual bool verifyPayment(const std::string& transactionId) = 0;
    virtual ~PaymentProvider() = default;
};

class PayPalAdapter : public PaymentProvider {
private:
    PayPal paypal;
public:
    void processPayment(const std::string& item) override {
        paypal.makePayment(item);
    }
    
    void refundPayment(const std::string& item) override {
        paypal.refundPayment(item);
    }
    
    bool verifyPayment(const std::string& transactionId) override {
        return paypal.verifyPayment(transactionId);
    }
};

class StripeAdapter : public PaymentProvider {
private:
    Stripe stripe;
public:
    void processPayment(const std::string& item) override {
        stripe.chargePayment(item);
    }
    
    void refundPayment(const std::string& item) override {
        stripe.issueRefund(item);
    }
    
    bool verifyPayment(const std::string& transactionId) override {
        return stripe.verifyCharge(transactionId);
    }
};

class PaymentGateway {
private:
    std::unordered_map<std::string, PaymentProvider*> providers;
public:
    void addProvider(const std::string& name, PaymentProvider* provider) {
        providers[name] = provider;
    }
    
    void processPayment(const std::string& provider, const std::string& item) {
        if(providers.find(provider) != providers.end()) {
            providers[provider]->processPayment(item);
        }
    }
    
    void refundPayment(const std::string& provider, const std::string& item) {
        if(providers.find(provider) != providers.end()) {
            providers[provider]->refundPayment(item);
        }
    }
};

int main() {
    PaymentGateway gateway;
    gateway.addProvider("PayPal", new PayPalAdapter());
    gateway.addProvider("Stripe", new StripeAdapter());
    
    gateway.processPayment("PayPal", "Laptop");
    gateway.refundPayment("Stripe", "Phone");
    
    return 0;
}
