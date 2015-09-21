/* The file is part of Snowman decompiler. */
/* See doc/licenses.asciidoc for the licensing information. */

#include <nc/config.h>

#include <memory>

#include <QLatin1String>

#include "Expression.h"
#include "Types.h"

namespace nc {
namespace core {
namespace likec {

/**
 * An identifier not declared anywhere.
 * Useful for representing intrinsic functions.
 */
class UndeclaredIdentifier: public Expression {
    QLatin1String name_;
    std::unique_ptr<Type> type_;

public:
    /**
     * \param name Name of the identifier function.
     * \param type Valid pointer to the type of the intrinsic function.
     */
    UndeclaredIdentifier(QLatin1String name, std::unique_ptr<Type> type)
        : Expression(Expression::UNDECLARED_IDENTIFIER), name_(std::move(name)), type_(std::move(type)) {}

    /**
     * \return Name of the identifier.
     */
    const QLatin1String &name() const { return name_; }

    /**
     * \return Valid pointer to the type of the intrinsic function.
     */
    const Type *type() const { return type_.get(); }

protected:
    void doPrint(PrintContext &context) const override;
};

} // namespace likec
} // namespace core
} // namespace nc

NC_SUBCLASS(nc::core::likec::Expression, nc::core::likec::UndeclaredIdentifier,
            nc::core::likec::Expression::UNDECLARED_IDENTIFIER)

    /* vim:set et sts=4 sw=4: */